#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char *buf[] = {"aaa", "bbb"};
    if (isatty(fileno(stdout))){
        printf("%s %s\n", buf[0], buf[1]);
    }
    else {
        printf("%s\n%s\n", buf[0], buf[1]);
    }
    return 0;
}
