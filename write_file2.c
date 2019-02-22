//write_file2.c
#include <stdio.h>

void main(void)
{
    char myName[] = {"YamadaKouji"};
    int myNumber = 96131028;
    FILE *fp;  // file pointer

    // file open
    fp = fopen("test.dat","w");

    // file write
    fprintf(fp, "%s %d\n", myName, myNumber);
    fprintf(fp, "%d,%s\n", myNumber, myName);

    printf("%s %d\n",myName,myNumber);
    printf("%d,%s\n",myNumber,myName);

    fclose(fp);
}
