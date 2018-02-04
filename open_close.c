//open_close.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    fd = open("test.txt", O_CREAT|O_WRONLY|O_TRUNC);
    if (fd == -1){
        fprintf(stderr, "Can not open file:%s\n", "test.txt");
    }
    printf("Open OK:%d\n", fd);
    close(fd);
    return 0;
}
