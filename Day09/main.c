/*
* 2016-07-15 ~ 2016-08-13
* 이진트리
* main.c
* Cellularhacker
* GNU General Public License v3.0
*/

#include "binarytree.h"

void cmdErrorHandlingFunc(char* errMessage);
void cmdMainScreenFunc();

int quit_code = 1; 

int main(void) {
    Node *default_root = NULL;
    int Number;
    char op;

    cmdMainScreenFunc(default_root);

    while(quit_code != 0) {
        fflush(stdin);
        scanf("%c", &op);
        
        switch(op) {
            case '1':
                fflush(stdin);
                printf("Input Value to Add: ");
                scanf("%d", &Number);
                fflush(stdin);
                if(default_root == NULL) default_root = CreateNode(Number);
                else InsertNode(default_root, Number);
                break;
            case '2':
                fflush(stdin);
                printf("Input Value to Remove: ");
                scanf("%d", &Number);
                fflush(stdin);
                default_root = removeNode(default_root, Number);
                break;
            case '3':
                printf("\n");
                PreOrderPrintTree(default_root);
                break;
            case '4':
                printf("\n");
                InOrderPrintTree(default_root);
                break;
            case '5':
                printf("\n");
                PostOrderPrintTree(default_root);
                break;
            case '6':
                DestroyTree(default_root);
                break;
            case 'Q':
            case 'q':
                    DestroyTree(default_root);
                    printf("Good bye\n");
                    return 0;
                break;
            case ' ':
            case '\n':
                fflush(stdin);
                continue;
            default:
                cmdErrorHandlingFunc("Wrong Operation");

        }

        fflush(stdin);
        cmdMainScreenFunc(default_root);
    }

    return 0;
}

// Additional Functions.
void cmdMainScreenFunc() {
    printf("\n========================================\n");
    printf("1. Add a new node with Integer value\n");
    printf("2. Remove the node with Integer value\n");
    printf("3. Print the Tree with \'PreOrder\'\n");
    printf("4. Print the Tree with \'InOrder\'\n");
    printf("5. Print the Tree with \'PostOrder\'\n");
    printf("6. Destroy \'all of the Tree\'\n");
    printf("\'Q\' or \'q\' to quit.\n");
    printf("========================================\n");
    printf(">>> ");
}

void cmdErrorHandlingFunc(char* errMessage) {
    printf("Error: %s\n",errMessage);
}