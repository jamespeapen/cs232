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

#define N_CUSTOMERS = 10;

// semaphores
sem_t sem_baker;
sem_t sem_cashier;

/**
 * Baking function
 */
void *baking();

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
    pthread_create(&thread_baker, NULL, baking, NULL);
}

