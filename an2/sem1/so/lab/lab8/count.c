#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#define MAX_RESOURCES 5

int available_resources = MAX_RESOURCES;
pthread_mutex_t mtx;

// daca facem increase inseamna ca eliberam resurse
int increase(int count) {
    pthread_mutex_lock(&mtx);
    available_resources += count;
    printf("Released %d resources %d remaining\n", count, available_resources);
    pthread_mutex_unlock(&mtx);

    return 0;
}

// iar daca facem decrease inseamna ca reducem din resurse
int decrease(int count) {
    pthread_mutex_lock(&mtx);
    if (available_resources < count) {
        pthread_mutex_unlock(&mtx); 
        return -1;
    }
    else {
        available_resources -= count;
        printf("Got %d resources %d remaining\n", count, available_resources);
    }
    pthread_mutex_unlock(&mtx);
    return 0;
}

void *start_routine(void *c) {
    int count = (int)c;
    decrease(count);
    increase(count);
    return NULL;
}

int main() {
    
    if (pthread_mutex_init(&mtx, NULL)) {
        perror(NULL);
        return errno;
    }

    printf("MAX_RESOURCES = %d\n", available_resources);

    pthread_t threads[10];

    for (int i = 0; i < 10; i++) {
        int count = rand() % (MAX_RESOURCES + 1);
        if (pthread_create(&threads[i], NULL, start_routine, count)) {
            perror(NULL);
            return errno;
        }
    }

    for (int i = 0; i < 10; i++) {
        if (pthread_join(threads[i], NULL)) {
            perror(NULL);
            return errno;
        }
    }

    pthread_mutex_destroy(&mtx); 

    return 0;
}
