#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char *buf[] = {"aaa", "bbb"};
    printf("%s %s\n", buf[0], buf[1]);
    return 0;
}
