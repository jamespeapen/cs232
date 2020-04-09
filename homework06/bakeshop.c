/**
 * Bakeshop program 
 * @author: James Eapen (jpe4)
 * @data: 2020 Apr 11
 * protect: no. of customers in the store 
 *          no. of loaves baked
 *          customer status
 */

#define _DEFAULT_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define MAX_CUSTOMERS 5
#define N_CUSTOMERS  10
#define TIME_TO_BAKE 100000

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
int n_loaves = 0;
int n_customers  = 0;
int n_customers_in_store = 0;

/**
 * Baking function
 */
void *baking()
{
    sem_wait(&sem_baker);
    while(n_loaves < 10)
    {
        printf("Baker: Here I am baking a loaf of bread...\n");
        usleep(TIME_TO_BAKE);
        n_loaves++;
    }
    printf("All loaves baked!\n");
    sem_post(&sem_baker);
}

/**
 * Buying function for customers
 */
void *buying() 
{
    if (n_customers < MAX_CUSTOMERS)
    {
        n_customers_in_store++;
        if (n_loaves > 0);
            n_loaves--;
    }
}

/**
 * Bakeshop driver
 */
int main() 
{
    // initialize semaphores
    sem_init(&sem_baker, 0, 1);
    sem_init(&sem_customer, 0, 1);

    printf("Busy Bakeshop is starting up...\n"); 
    printf("No. of loaves: %d\n", n_loaves);
    printf("No. of customers: %d\n", n_customers);

    pthread_create(&thread_baker, NULL, baking, NULL);
    pthread_join(thread_baker, NULL);

    for (unsigned i = 0; i < N_CUSTOMERS; i++) 
    {
        pthread_create(&ts[i], NULL, buying, NULL);
    }

    // exit after all threads have exited
    pthread_exit(NULL);
}

