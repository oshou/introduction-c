//file_pos.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    off_t pos;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0){
        return 1;
    }

    pos = lseek(fd, 0, SEEK_END);
    printf("file size:%ld\n", pos);

    pos = lseek(fd, 0, SEEK_SET);

    pos = lseek(fd, 0, SEEK_CUR);
    printf("file pos:%ld\n", pos);

    return 0;
}
