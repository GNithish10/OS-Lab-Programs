#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#define FIFO_NAME "myfifo"
int main()
{
    int fd;
    const char *message = "Hello from the writer process!\n";
    // Create the FIFO if it doesn't exist
    if (mkfifo(FIFO_NAME, 0666) == -1)
    {
        perror("mkfifo");
    }
    // Open the FIFO for writing
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    // Write the message to the FIFO
    write(fd, message, sizeof(char) * (strlen(message) + 1));
    printf("Writer: Message sent to the pipe.\n");
    // Close the FIFO
    close(fd);
    return 0;
}
