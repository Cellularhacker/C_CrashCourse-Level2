/*
* 2016-07-15 ~ 2016-08-13
* Checking Decimal Value
* Check_Dec.c
* Cellularhacker
* GNU General Public License v3.0
*/

#include <stdio.h>

int main(void) {
    char c;

    while(1){
        fflush(stdin);
        printf("Input: ");
        scanf("%c", &c);
        printf("Dec:%d, Hex:%x, Char:%c \n",c,c,c);
        getchar();
        fflush(stdin);
    }

}