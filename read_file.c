//read_file.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char buffer[512];
    ssize_t ret;
    ssize_t read_size=0;

    // read(type:read-only)
    fd = open("sample", O_RDONLY);
    // exception handling
    if (fd < 0){
        fprintf(stderr, "open() error: %d\n", fd);
        return 1;
    }

    while (1){
        //read the specified size from file-descriptor to buf
        ret = read(fd, buffer, sizeof(buffer));
        if (ret < 0){
            fprintf(stderr, "read() error:%d\n", fd);
            close(fd);
            return 1;
        }

        if (ret == 0){
            break;
        }
        read_size += ret;
    }
    close(fd);
    printf("read size=%ld\n", read_size);
    return 0;
}
