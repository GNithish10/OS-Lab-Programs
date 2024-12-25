#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
int main() 
{
    pid_t pid;
    int status;
    // Create a child process
    pid = fork();
    if (pid < 0)
    {
        // fork failed
        perror("Fork failed");
        exit(1);
    } 
    else if (pid == 0)
    {
        // Child process
        printf("Child process (PID: %d) is running...\n", getpid());
        // Uncomment one of the following lines to test different termination scenarios
        exit(0);            // Normal termination
        // exit(1);            // Normal termination with exit status 1
        // abort();            // Abnormal termination
        // raise(SIGKILL);     // Abnormal termination by signal
    } 
    else 
    {
        // Parent process
        printf("Parent process (PID: %d) is waiting for child process (PID: %d)...\n", getpid(), pid);
        waitpid(pid, &status, 0); // Wait for the specific child process
        if (WIFEXITED(status))
        {
                    // Child process terminated normally
            printf("Child process terminated normally with exit status %d.\n", WEXITSTATUS(status));
        } 
        else if (WIFSIGNALED(status)) 
        {
            // Child process terminated by a signal
            printf("Child process terminated abnormally by signal number %d.\n", WTERMSIG(status));
        } 
        else if (WIFSTOPPED(status))
        {
                // Child process was stopped by a signal
            printf("Child process stopped by signal number %d.\n", WSTOPSIG(status));
        } 
        else 
        {
            // Other cases
            printf("Child process terminated with unknown status.\n");
        }
    }

    return 0;
}
