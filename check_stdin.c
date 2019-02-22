#include <stdio.h>
#include <unistd.h>

int main(void)
{
    if (isatty(fileno(stdin))){
        printf("stdin:terminal\n");
    }
    else {
        printf("stdin:pipe\n");
    }
    if (isatty(0)){
        printf("stdin:terminal\n");
    }
    else {
        printf("stdin:pipe\n");
    }

    return 0;
}
