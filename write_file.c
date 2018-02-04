//write_file.c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(void)
{
    int fd;
    int old_errno;
    char buf[512] = {};
    ssize_t ret;

    fd = open("test.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH);
    if (fd < 0){
        fprintf(stderr, "open(2) error:%d\n", fd);
        return 1;
    }

    ret = write(fd, buf, sizeof(buf));
    if (ret < 0){
        old_errno = errno;
        if (old_errno == ENOSPC){
            fprintf(stderr, "Error: No left on space.\n");
        }
        return 1;
    }

    close(fd);
    printf("buffer size=%ld, write size=%ld\n", sizeof(buf), ret);
    return 0;
}
