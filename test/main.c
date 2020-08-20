#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "head/xxx.h"
#include "head/aaa.h"

int main1(int agrc,char* agrv[]) {
    printf("%s\n%d\n",agrv[1],atoi(agrv[2]));
    PRINT;
    PRINTX(2*3);
    PRINTXY(2*3,2);
    HUANHANG;
    printf("%s\n",PRINTSTR("eeeeeeeeeeeeeeeee"));
    printf("%s\n",ADDSTR("rrrrr","ttttt"));
    printf("%d\n",MAX(11,12));
    printf("1111\n");
    sum(1,2);
    tfun();

    //random number seed
    srand((unsigned int)time(NULL));
    printf("%d\n",rand());

    //file io test 
    filetest();

    return 0;
}

void filetest()
{
    FILE *oFile = fopen("/home/test/README.md","r");

}