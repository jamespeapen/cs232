/**
 * Bakeshop that uses semaphores to control resources 
 * @author: James Eapen (jpe4)
 * @date: 2020 Apr 11
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

// consts
#define MAX_CUSTOMERS 5
#define N_CUSTOMERS  10

/** GLOBAL VARIABLES */

// pthread identifiers
pthread_t thread_baker;
pthread_t thread_cashier;
pthread_t customer_threads[N_CUSTOMERS];      // customer thread array

// semaphores
sem_t sem_baker;
sem_t sem_customer;
sem_t sem_store_capacity;

// counts
int n_loaves_baked = 0;
int n_available_loaves = 0;
int n_loaves_to_checkout = 0;

int n_customers_checkedout = 0;
int n_customers_in_store = 0;

// checkout line
int customers_checking_out[10];

/**
 * Baking function
 * Needs release from cash register and releases after every loaf
 */
void *baking()
{
    // nanosleep settings
    struct timespec tim1;
    tim1.tv_sec = 1;
    tim1.tv_nsec = 0;

    while(n_loaves_baked < 10)
    {
        sem_wait(&sem_baker);

        fprintf(stderr, "\nBaker: Here I am baking a loaf of bread...\n");
        n_loaves_baked++;
        n_available_loaves++;
        fprintf(stderr, "Loaf %d baked. %d loaves available for sale\n", n_loaves_baked, n_available_loaves);
        
        sem_post(&sem_baker);
        nanosleep(&tim1, &tim1);
    }        
    
    fprintf(stderr, "\nAll loaves baked!\n");
}

/**
 * Buying function for customers
 * while the max number of customers have not been checked out, 
 * go to the queue and hold a customer, wait for the baker to come, 
 * checkout every customer in queue as long as the are loaves to checkout
 * release baker to bake
 */
void *buying() 
{
    // nanosleep settings
    struct timespec tim1;
    tim1.tv_sec = 2;
    tim1.tv_nsec = 0;

    while (n_customers_checkedout < N_CUSTOMERS)
    {
        // if there is a customer_checkingout
        if (n_loaves_to_checkout > n_customers_checkedout)
        {
            fprintf(stderr, "\nCustomer %d is waiting to be checked out\n", customers_checking_out[n_customers_checkedout]);

            // keep customer at the checkout
            sem_wait(&sem_customer);

            //wait for the baker to be released to cashier
            sem_wait(&sem_baker);
            fprintf(stderr, "Baker comes to cash register\n");

            fprintf(stderr, "Customer %d has paid\n", customers_checking_out[n_customers_checkedout]);
            nanosleep(&tim1, &tim1); 
            fprintf(stderr, "Baker has handed Customer %d the receipt\n", customers_checking_out[n_customers_checkedout]);
            fprintf(stderr, "Customer %d has received receipt\n", customers_checking_out[n_customers_checkedout]);
            n_customers_checkedout++;

            // release for another customer to checkout
            sem_post(&sem_customer);

            //release cashier to bake
            sem_post(&sem_baker);
            fprintf(stderr, "Baker returns to bake\n");
            nanosleep(&tim1, &tim1);
        }
    }

}

/** 
 * Getting loaf and exiting store
 * @params: thread/customer id pointer
 * allow one customer in at a time till max customers is reached
 * each customer waits for a loaf and only one can get it at a time
 * add customer with loaf to checkout line
 * wait for checkout before allowing another customer in
 */
void *get_in_get_loaf(void *id) 
{
    // nanosleep settings
    struct timespec tim1;
    tim1.tv_sec = 1;
    tim1.tv_nsec = 0;

    // get id from void *id
    int customer_id = *(int*) id;

    // cap no of customers at 5
    sem_wait(&sem_store_capacity);
    
    // allow only one customer in at a time
    sem_wait(&sem_customer);
    n_customers_in_store++;
    fprintf(stderr, "\nCustomer %d entered store. Customers: %d \n", customer_id, n_customers_in_store);
    sem_post(&sem_customer);

    //wait for a loaf to be available
    sem_wait(&sem_customer);
    while(n_available_loaves == 0)
    {
        nanosleep(&tim1, &tim1);
    }

    // allow only one customer to get a loaf at a time
    n_available_loaves--;
    fprintf(stderr, "Customer %d has a loaf of bread\n", customer_id);
    n_loaves_to_checkout++;

    // add customer to the checkout line
    customers_checking_out[n_loaves_to_checkout-1] = customer_id;
    
    // release after picking up to allow another customer to pick up bread
    sem_post(&sem_customer);
    
    // wait to checkout before leaving
    while (n_customers_checkedout < n_loaves_to_checkout) {
        nanosleep(&tim1, &tim1);
    }

    // allow only one customer to leave at a time
    sem_wait(&sem_customer);
    n_customers_in_store--;
    fprintf(stderr, "Customer %d has left the bakeshop. Customers in the shop: %d\n", customer_id, n_customers_in_store);
    
    //alllow another customer to leave
    sem_post(&sem_customer);

    // allow another customer into the store
    sem_post(&sem_store_capacity);
    nanosleep(&tim1, &tim1);
}

/**
 * Bakeshop driver
 * create the baker, cashier, and customer threads
 */
int main() 
{
    // initialize semaphores
    sem_init(&sem_baker, 0, 1);
    sem_init(&sem_customer, 0, 1);  // keep only 5 threads in store at a time
    sem_init(&sem_store_capacity, 0, MAX_CUSTOMERS);

    fprintf(stderr, "Busy Bakeshop is starting up...\n"); 

    pthread_create(&thread_baker, NULL, baking, NULL);
    pthread_create(&thread_cashier, NULL, buying, NULL);

    //customer threads
    for (int i = 0; i < N_CUSTOMERS; i++) 
    {
        int *id = malloc(sizeof(*id));
        *id = i;
        pthread_create(&customer_threads[i], NULL, get_in_get_loaf, id);
    }

    for (int i = 0; i < N_CUSTOMERS; i++) 
    {
        pthread_join(customer_threads[i], NULL);
    }
    pthread_join(thread_baker, NULL);
   // exit after all threads have exited
    pthread_exit(NULL);
}

