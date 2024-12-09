//Write a C program to simulate race condition

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
static void charatatime(char *);
int main()
{
        int pid;
        if((pid=fork())<0)
                printf("fork error\n");
        else if(pid==0)
                charatatime("output from child\n");
        else
        {
                wait(NULL);
                charatatime("output from parent\n");
        _exit(0);
}
static void charatatime(char *str)
{
        char *ptr;
        int c;
        setbuf(stdout,NULL);
        for(ptr=str;(c=*ptr++)!=0;)
                putc(c,stdout);
}

/*Output:
output from parent
output from child
*/
