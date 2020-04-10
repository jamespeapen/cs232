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
#define TIME_TO_BAKE 1000000

/** GLOBAL VARIABLES */

// pthread identifiers
pthread_t thread_baker;
pthread_t thread_cashier;
pthread_t ts[N_CUSTOMERS];      // customer thread array

// semaphores
sem_t sem_baker;
sem_t sem_cashier;
sem_t sem_customer;

// counts
int n_loaves_baked = 0;
int n_available_loaves = 0;
int n_customers  = 0;
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

        printf("Baker: Here I am baking a loaf of bread...\n");
        n_available_loaves++;
        n_loaves_baked++;
        printf("Loaf %d baked. %d loaves available for sale\n", n_loaves_baked, n_available_loaves);
        
        sem_post(&sem_baker);
        nanosleep(&tim1, &tim1);
    }        
    
    printf("All loaves baked!\n");
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
    if (n_customers_in_store < 5)
    {
        printf("Customer %d waiting for loaf \n", *(int *)id);
        if (n_available_loaves > 1)
        {
            sem_wait(&sem_customer); 
            n_available_loaves--;
            printf("loaf selected by Customer %d. %d loaves left", *(int *)id, n_available_loaves);
            sem_post(&sem_customer);
        }
    }
}

/**
 * Bakeshop driver
 */
int main() 
{
    // initialize semaphores
    sem_init(&sem_baker, 0, 1);
    sem_init(&sem_cashier, 0 , 1);
    sem_init(&sem_customer, 0, 1);  // keep only 5 threads in store at a time

    printf("Busy Bakeshop is starting up...\n"); 

    pthread_create(&thread_baker, NULL, baking, NULL);
    pthread_create(&thread_cashier, NULL, buying, NULL);

    //customer threads
    for (int i = 0; i < N_CUSTOMERS; i++) 
    {
        int *id = malloc(sizeof(*id));
        *id = i;
        pthread_create(&ts[i], NULL, get_loaf, id);
    }

    for (int i = 0; i < N_CUSTOMERS; i++) 
    {
        pthread_join(ts[i], NULL);
    }
    pthread_join(thread_baker, NULL);
   // exit after all threads have exited
    pthread_exit(NULL);
}

