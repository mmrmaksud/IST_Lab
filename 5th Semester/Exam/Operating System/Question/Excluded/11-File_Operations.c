//Write a C program to perform basic file operations: create, write, read, and delete a file. Use system calls like open(), read(), write(), and unlink().

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("testfile.txt", O_CREAT | O_WRONLY, 0644);
    write(fd, "Hello, file system!\n", 20);
    close(fd);

    fd = open("testfile.txt", O_RDONLY);
    char buffer[100];
    read(fd, buffer, sizeof(buffer));
    printf("File content: %s\n", buffer);
    close(fd);

    unlink("testfile.txt");
    return 0;
}
