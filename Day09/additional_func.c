/*
* 2016-08-13
* 이진트리
* basic_func.c
* Cellularhacker
* GNU General Public License v3.0
*/
void cmdMainScreenFunc() {
    printf("========================================\n");
    printf("1. Add a new node with Integer value\n");
    printf("2. Remove the node with Integer value\n");
    printf("3. Print the Tree with \'PreOrder\'\n");
    printf("4. Print the Tree with \'InOrder\'\n ");
    printf("5. Print the Tree with \'PostOrder\'\n");
    printf("6. Destroy \'all of the Tree\'\n");
    printf("\'Q\' or \'q\' to quit.\n");
    printf("========================================\n");
    printf(">>> ");
}
void cmdSelectFunc() {
    int op, Number;

    scanf("&d", &op);
    switch(op) {
        case 1:
            printf("Input Value to Add: ");
            scanf("%d", &Number);
            if(default_root == NULL) CreateNode(Number);
            else InsertNode(default_root, Number);
            break;
        case 2:
            printf("Input Value to Remove: ");
            scanf("%d", &Number);
            removeNode(default_root, Number);
            break;
        case 3:
            printf("\n");
            PreOrderPrintTree(default_root);
            break;
        case 4:
            printf("\n");
            InOrderPrintTree(default_root);
            break;
        case 5:
            printf("\n");
            PostOrderPrintTree(default_root);
            break;
        case 6:
            printf("Are you sure to Destroy the all of the Tree?(y/N): ");
            scanf("%d", &Number);
            if(Number == 'y' || Number == 'Y') DestroyNode(default_root);
            else printf("Skipping Destroy the Tree.\n");
            break;
        case 'q':
        case 'Q':
            printf("Are you sure to quit?(y/N): ");
            if(Number == 'y' || Number == 'Y') {
                DestroyNode(default_root);
                printf("Good bye\n");
                exit(1);
            }
        default:
            cmdErrorHandlingFunc("Wrong Operation");

    }
}
void cmdErrorHandlingFunc(char* errMessage) {
    printf("Error: %s\n",errMessage);
}