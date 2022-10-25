#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){
	
	size_t bytes = 100;
	char* buffer = (char*)malloc(bytes * sizeof(char));
	int fd = open(argv[1], O_RDONLY);	

	int fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);

	size_t nread = read(fd, buffer, bytes);
	while (nread > 0) {
		write(fd2, buffer, nread);
		nread = read(fd, buffer, bytes);
	}
	return 0;
}
