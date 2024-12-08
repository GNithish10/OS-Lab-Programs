/*symlink() creates a symbolic link named newpath which contains the string oldpath.

symlink() creates a new symbolic link (also known as a soft link) to an existing file.
S = symlink(FILE1, FILE2), creates a soft link named FILE2 to an existing FILE1.

Return Value: On success, zero is returned. On error, -1 is returned, and errno is set appropriately.*/

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
  
int main(int argc, char* argv[]) 
{ 
    // Symlink function 
    int sl = symlink(argv[1], argv[2]); 
  
    // argv[1] is existing file name 
    // argv[2] is soft link file name 
    if (sl == 0) { 
        printf("Soft Link created"
               " successfully"); 
    } 
  
    return 0; 
}

/*Output:
guest-Mojblw@ubuntu:~$ gcc softlink.c
guest-Mojblw@ubuntu:~$ ./a.out link.txt link2.txt
Soft Link created successfully
guest-Mojblw@ubuntu:~$ ls -l
lrwxrwxrwx 2 guest-Mojblw guest-Mojblw   link2.txt -> link.txt
-rw-rw-r-- 2 guest-Mojblw guest-Mojblw   link.txt
*/
