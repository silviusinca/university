#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    /* /usr/bin/ls */
    pid_t pid = fork();
    if (pid < 0) {
        return errno;
    }
    else if (pid == 0) {
        char *argv[] = { "ls", NULL };
        execve("/usr/bin/ls", argv, NULL);
        perror(NULL);
    }
    else {
        printf("My PID = % d, Child PID = % d \n", getppid(), getpid());
        wait(NULL);
        printf("Child %d finished\n", getpid());
    }


    return 0;
}