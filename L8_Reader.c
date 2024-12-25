//Write C programs that illustrate communication between two unrelated processes using named pipe (FlFO file).

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define FIFO_NAME "myfifo"
int main()
 {
    int fd;
    char buffer[100];
    // Open the FIFO for reading
    fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    // Read the message from the FIFO
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead > 0) {
        printf("Reader: Message received - %s", buffer);
    }

    // Close the FIFO
    close(fd);
    // Optionally remove the FIFO
    unlink(FIFO_NAME);
    return 0;
}
