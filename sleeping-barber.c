#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_CHAIRS 1
#define NUM_CUSTOMERS 5

sem_t barberReady;
sem_t customerReady;
sem_t accessSeats;

int numFreeSeats = NUM_CHAIRS;

void* barber(void* arg) {
    while(1) {
        sem_wait(&customerReady);
        sem_wait(&accessSeats);
        numFreeSeats++;
        sem_post(&barberReady);
        sem_post(&accessSeats);
        printf("Barber is cutting hair...\n");
        sleep(2);
    }
}

void* customer(void* arg) {
    int customerID = *(int*)arg;
    printf("Customer %d is entering the shop...\n", customerID);
    sem_wait(&accessSeats);
    if(numFreeSeats > 0) {
        numFreeSeats--;
        printf("Customer %d is sitting in the chair. Waiting...\n", customerID);
        sem_post(&customerReady);
        sem_post(&accessSeats);
        sem_wait(&barberReady);
        printf("Customer %d is getting a haircut...\n", customerID);
    }
    else {
        sem_post(&accessSeats);
        printf("Customer %d is leaving the shop...\n", customerID);
    }
}

int main(int argc, char* argv[]) {
    sem_init(&barberReady, 0, 0);
    sem_init(&customerReady, 0, 0);
    sem_init(&accessSeats, 0, 1);

    pthread_t barberThread;
    pthread_create(&barberThread, NULL, barber, NULL);

    pthread_t customerThreads[NUM_CUSTOMERS];
    int customerIDs[NUM_CUSTOMERS];

    for(int i = 0; i < NUM_CUSTOMERS; i++) {
        customerIDs[i] = i;
        pthread_create(&customerThreads[i], NULL, customer, &customerIDs[i]);
        sleep(1);
    }

    for(int i = 0; i < NUM_CUSTOMERS; i++) {
        pthread_join(customerThreads[i], NULL);
    }

    return 0;
}
