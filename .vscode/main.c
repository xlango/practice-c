#include <stdio.h>
#include <stdlib.h>
#include "head/xxx.h"
#include "head/aaa.h"

int main1(void) {
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
    return 0;
}