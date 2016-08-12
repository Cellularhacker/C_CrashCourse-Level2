/*
* 2016-07-15 ~ 2016-08-13
* 이진트리
* main.c
* Cellularhacker
* GNU General Public License v3.0
*/

#include "binarytree.h"

int quit_code = 1; 

int main(void) {
    Node *default_root = NULL;
    while(quit_code != 0) {
        cmdMainScreenFunc(default_root);
        cmdSelectFunc(default_root);
    }

    return 0;
}

