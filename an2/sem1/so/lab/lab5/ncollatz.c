#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    printf("Starting parent %d\n", getpid());
    for (int i = 1; i <= argc; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            return errno;
        }
        else if (pid == 0) {
            int n = atoi(argv[i]);
            while (n != 1) {
                printf("%d ", n);
                if (n % 2 == 0)
                    n /= 2;
                else 
                    n = 3*n+1;
            }
            printf("%d\n", n);
        }
        else {
            wait(NULL);
            printf("Done parent %d Me %d \n", getppid(), getpid());
            exit(0);
        }
    }
    return 0;
}
