/**
 * Bakeshop program 
 * @author: James Eapen (jpe4)
 * @data: 2020 Apr 11
 */


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define N_CUSTOMERS  10

// semaphores
sem_t sem_baker;
sem_t sem_cashier;

/**
 * Baking function
 */
void *baking()
{
    printf("baking...");
}

/**
 * Buying function for customers
 */
void *buying() 
{
    printf("buying");
}

/**
 * Bakeshop driver
 */
int main() 
{
    int n_loaves = 0;
    int n_customers  = 0;
    printf("Busy Bakeshop is starting up...\n"); 
    printf("No. of loaves: %d\n", n_loaves);
    printf("No. of customers: %d\n", n_customers);

    pthread_t thread_baker;
    pthread_t thread_cashier;
    pthread_t ts[N_CUSTOMERS];

    for (unsigned i = 0; i < N_CUSTOMERS; i++) 
    {
        pthread_create(&ts[i], NULL, buying, NULL);
    }
    pthread_create(&thread_baker, NULL, baking, NULL);
    pthread_join(thread_baker, NULL);

    // exit after all threads have exited
    pthread_exit(NULL);
}

