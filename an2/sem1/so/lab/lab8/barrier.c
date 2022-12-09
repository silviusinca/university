#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <semaphore.h>
#include <pthread.h>
#define NTHRS 5

sem_t sem;
pthread_mutex_t mtx;
int S=0;

void barrier_point() {
    pthread_mutex_lock(&mtx);
    S++;
    pthread_mutex_unlock(&mtx);
    if (S < NTHRS) {
        // scade valoarea cu o unitate
        if (sem_wait(&sem)) { 
            perror(NULL); 
            return errno;
        }
    }
    else {
        for (int i = 0; i < NTHRS; i++) {
            // creste valoarea cu o unitate si elibereaza thread-ul care asteapta de cel mai mult timp
            sem_post(&sem); 
        }
    }
}

void *tfun(void *v) {
	int *tid = (int *)v;
	printf("%d reached the barrier \n",*tid);
	barrier_point();
	printf("%d passed the barrier \n", *tid);

	free(tid);
	return NULL;
}

int main() {

    pthread_t thr[10];
	int i;

	if (sem_init(&sem, 0, S)) { 
	    perror(NULL);
        return errno;
    }

	if (pthread_mutex_init(&mtx, NULL)) {
        perror(NULL); 
        return errno;
    }

    printf("NTHRS = %d\n", NTHRS);

	for (i = 0; i < NTHRS; i++) {
        int *k = (int *)malloc(sizeof(int));
        *k = i;
		if (pthread_create(&thr[i], NULL, tfun, k)) {
            perror(NULL); 
            return errno;
        }
	}

    for (i = 0; i < NTHRS; i++) {
        if (pthread_join(thr[i], NULL)) {
            perror(NULL); 
            return errno;
        }
    }
    sem_destroy(&sem); 
    pthread_mutex_destroy(&mtx); 

    return 0;
}
