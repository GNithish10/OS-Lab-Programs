//Write a C program to demonstrate multitasking using fork ( ) system call.

#include <stdio.h>
#include <unistd.h>  // For fork() and getpid()
#include <sys/wait.h> // For wait()

int main() {
    pid_t pid;

    // Create a new process
    pid = fork();

    if (pid < 0) {
        // Error occurred during fork
        printf("Fork failed!\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child process: My process ID is %d\n", getpid());
        printf("Child process is performing task 1...\n");
        sleep(2); // Simulate task execution
        printf("Child process: Task 1 completed!\n");
    } else {
        // Parent process
        printf("Parent process: My process ID is %d\n", getpid());
        printf("Parent process is performing task 2...\n");
        sleep(3); // Simulate task execution
        printf("Parent process: Task 2 completed!\n");

        // Wait for the child process to finish
        wait(NULL);
        printf("Parent process: Child process has finished.\n");
    }

    return 0;
}

/*Output:
Parent process: My process ID is 3287
Parent process is performing task 2...
Child process: My process ID is 3288
Child process is performing task 1...
Child process: Task 1 completed!
Parent process: Task 2 completed!
Parent process: Child process has finished.
*/