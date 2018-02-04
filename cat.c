#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static void do_cat(const char *path);
static void die(const char *s);

int main(int argc, char *argv[])
{
    int i;
    // exception handling(arguments not defined)
    if (argc < 2){
        fprintf(stderr, "%s: file name not given\n", argv[0]);
    }
   // repeat as many command line arguments
   for (i = 1; i < argc; i++){
        do_cat(argv[i]);
    }
    exit(0);
}

#define BUFFER_SIZE 2048

static void do_cat(const char *path)
{

    int fd;
    unsigned char buf[BUFFER_SIZE];
    int n;

    // open
    fd = open(path, O_RDONLY);
    // exception handling
    if (fd < 0) die(path);
    // Infinite loop
    for (;;){
        // read buf-size-data from "fd" && store "buf"
        n = read(fd, buf, sizeof buf);
        // exception handling(read error)
        if (n < 0) die(path);
        // if file reaches the end, exit
        if (n == 0) break;
        // write buffer contents to STDOUT
        if (write(STDOUT_FILENO, buf, n) < 0) die(path);
    }
    if (close(fd) < 0) die(path);
}

static void die(const char *s)
{
    perror(s);
    exit(1);
}
