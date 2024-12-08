//Write a C program that illustrates how zombie child processes are created.

/*A process which has finished the execution but still has entry in the process table to report to its parent process is known as a zombie process.
A child process always first becomes a zombie before being removed from the process table. 
The parent process reads the exit status of the child process which reaps off the child process entry from the process table*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
 
int main()
{
    int i;
    int pid = fork();
 
    if (pid == 0)
    {
        for (i=0; i<20; i++)
            printf("I am Child\n");
            exit(0)
    }
    else
    {
       sleep(30);
        printf("I am Parent\n");
        
    }
}