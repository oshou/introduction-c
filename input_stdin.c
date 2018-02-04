#include <stdio.h>

int main(void)
{
    int x;
    fscanf(stdin, "%d", &x);
    fprintf(stdout, "get:%d\n", x);
    return 0;
}
