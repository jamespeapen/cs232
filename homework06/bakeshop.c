/**
 * Bakeshop program 
 * @author: James Eapen (jpe4)
 * @data: 2020 Apr 11
 * protect: no. of customers in the store 
 *          no. of loaves baked
 *          customer status
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
sem_t sem_cashier;
sem_t sem_customer;
sem_t sem_store_capacity;

// counts
int n_loaves_baked = 0;
int n_available_loaves = 0;
int n_customers_done  = 0;
int n_customers_in_store = 0;

/**
 * Baking function
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
        fprintf(stderr, "\n");
        
        sem_post(&sem_baker);
        nanosleep(&tim1, &tim1);
    }        
    
    fprintf(stderr, "All loaves baked!\n");
}

/**
 * Buying function for customers
 */
void *buying() 
{

}

/** 
 * Getting loaf
 */
void *get_loaf(void *id) 
{
    // nanosleep settings
    struct timespec tim1;
    tim1.tv_sec = 1;
    tim1.tv_nsec = 0;

    sem_wait(&sem_customer);
    n_customers_in_store++;
    fprintf(stderr, "Customer %d entered store. Customers: %d \n", *(int*) id, n_customers_in_store);

    sem_wait(&sem_cashier);
    while (n_available_loaves == 0)
    {
        nanosleep(&tim1, &tim1);
    }
        fprintf(stderr, "%d loaves available\n", n_available_loaves);
        fprintf(stderr, "Customer %d got loaf and left. Customers: %d \n" , *(int*) id, n_customers_in_store);
        n_available_loaves--;
        n_customers_done++;
        n_customers_in_store--;
    
    sem_post(&sem_cashier);

    sem_post(&sem_customer);
    nanosleep(&tim1, &tim1);
}

/**
 * Bakeshop driver
 */
int main() 
{
    // initialize semaphores
    sem_init(&sem_baker, 0, 1);
    sem_init(&sem_cashier, 0 , 1);
    sem_init(&sem_customer, 0, 5);  // keep only 5 threads in store at a time
    sem_init(&sem_store_capacity, 0, 1);

    fprintf(stderr, "Busy Bakeshop is starting up...\n"); 

    pthread_create(&thread_baker, NULL, baking, NULL);
    pthread_create(&thread_cashier, NULL, buying, NULL);

    //customer threads
    for (int i = 0; i < N_CUSTOMERS; i++) 
    {
        int *id = malloc(sizeof(*id));
        *id = i;
        pthread_create(&customer_threads[i], NULL, get_loaf, id);
    }

    for (int i = 0; i < N_CUSTOMERS; i++) 
    {
        pthread_join(customer_threads[i], NULL);
    }
    pthread_join(thread_baker, NULL);
   // exit after all threads have exited
    pthread_exit(NULL);
}

