/*
* 2016-07-15 ~ 2016-08-13
* 이진트리
* main.c
* Cellularhacker
* GNU General Public License v3.0
*/

#include "binarytree.h"
#include "additional.h"


int main(void) {
    Node *root = NULL;
    Node *tmp;

    root = CreateNode(11);
    InsertNode(root, 5);
    InsertNode(root, 1);
    InsertNode(root, 7);
    InsertNode(root, 17);
    InsertNode(root, 15);
    InsertNode(root, 37);

    PreOrderPrintTree(root);
    printf("\n");
    getchar();
    InOrderPrintTree(root);
    printf("\n");
    getchar();
    PostOrderPrintTree(root);
    printf("\n");
    getchar();

    DestroyTree(root);

    return 0;
}