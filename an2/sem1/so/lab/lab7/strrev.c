#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// flag-ul -pthread la compilare

void* inversare(void* v) {
    char* sir = (char*) v;
    char* invers = (char*)malloc(sizeof(sir));

    int j = 0;
    for (int i = strlen(sir)-1; i >= 0; i--) {
        invers[j++] = sir[i];
    }

    invers[j] = NULL;

    return invers;
}

int main(int argc, char** argv) {
    char *x, *y;
    pthread_t thr;

    pthread_create(&thr, NULL, inversare, argv[1]); // cream un thread nou care va porni pentru a rula functia "inversare"

    pthread_join(thr, (void**)&y); // asteapta explicit firul de executie "thr" sa se termine; rezultatul functiei il avem in "y"

    printf("%s\n", (char*) y);

    free(y);

    return 0;
}

