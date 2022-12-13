#include <stdio.h>
#include <sys/types.h>
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>

int main(int argc, char **argv) {

    printf("Starting Parent: %d\n", getpid());
    char shm_name[] = "my_shm";
    int shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (shm_fd < 0) {
        perror(NULL);
        return errno ;
    }
    size_t page_size = getpagesize();
    size_t shm_size = argc * page_size; // fiecare proces copil va avea acces la o sectiune de page_size bytes din memorie

    if (ftruncate(shm_fd, shm_size) == -1) {
        perror(NULL);
        shm_unlink(shm_name);
        return errno;
    }
    char* shm_ptr;
    for (int i = 1; i < argc; i++) {
        shm_ptr = mmap(0, page_size, PROT_WRITE, MAP_SHARED, shm_fd, (i-1) * page_size); // offset de page_size * index; retinem continuu de unde va trebui sa porneasca urmatorul proces

        if (shm_ptr == MAP_FAILED) {
            perror(NULL);
            shm_unlink(shm_name);
            return errno;
        }

        // cream noul proces;
        pid_t pid = fork();
        if (pid < 0) {
            perror(NULL);
            return errno;
        }

        else if (pid == 0) {
            int n = atoi(argv[i]);
            shm_ptr += sprintf(shm_ptr, "%d: ", n);
            while (n != 1) {
                shm_ptr += sprintf(shm_ptr, "%d ", n);
                if (n % 2 == 0)
                    n /= 2;
                else 
                    n = 3*n+1;
            }
            shm_ptr += sprintf(shm_ptr, "1");
            printf("Done parent %d; me %d\n", getppid(), getpid());
            return 1;
        }
    }

    for (int i = 1; i < argc; i++) {
        wait(NULL); // asteptam sa se termine toate procesele
    }

    for(int i = 1; i < argc; i++)
    {
        shm_ptr = mmap(0, page_size, PROT_READ, MAP_SHARED, shm_fd, (i-1)*page_size);
		printf("%s\n", shm_ptr);
		munmap(shm_ptr, page_size);
	}

	shm_unlink(shm_name);  //sterge memoria creata cu shm_open
	printf("Done Parent %d Me %d\n", getppid(), getpid());
    
    return 0;
}
