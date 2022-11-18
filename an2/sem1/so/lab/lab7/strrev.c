#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

    pthread_create(&thr, NULL, inversare, argv[1]);

    pthread_join(thr, (void**)&y);

    printf("%s\n", (char*) y);

    return 0;
}

