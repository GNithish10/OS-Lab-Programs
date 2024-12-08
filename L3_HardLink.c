/*Hard Link: A hard link acts as a copy (mirrored) of the selected file. It accesses the data available in the original file.
If the earlier selected file is deleted, the hard link to the file will still contain the data of that file.

link() creates a new link (also known as a hard link) to an existing file.
L = link(FILE1, FILE2), creates a hard link named FILE2 to an existing FILE1.

Return Value: On success, zero is returned. On error, -1 is returned, and errno is set appropriately.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
int main(int argc, char* argv[]) 
{ 
    // Link function 
    int l = link(argv[1], argv[2]); 
    // argv[1] is existing file name 
    // argv[2] is link file name 
    if (l == 0) { 
        printf("Hard Link created successfully\n"); 
    } 
     return 0; 
}

/*Output:
guest-Mojblw@ubuntu:~$ gcc hardlink.c
guest-Mojblw@ubuntu:~$ ./a.out link.txt link1.txt
Hard Link created successfully
guest-Mojblw@ubuntu:~$ ls -l
-rw-rw-r-- 2 guest-Mojblw guest-Mojblw   link1.txt
-rw-rw-r-- 2 guest-Mojblw guest-Mojblw   link.txt
*/