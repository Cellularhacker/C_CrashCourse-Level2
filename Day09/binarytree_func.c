/*
* 2016-07-15 ~ 2016-08-13
* 이진트리
* basic.h
* Cellularhacker
* GNU General Public License v3.0
*/
#include "binarytree.h"

//Create A Node for New Tree
Node* CreateNode(int Number) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    printf("CreateNode Called\n");
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = Number;

    return newNode;
}


//Insert A Value in A Tree
void InsertNode(Node *node, int Number) {
    if(Number > node->data) {
        if(node->right != NULL) InsertNode(node->right, Number);
        else node->right = CreateNode(Number);
    } else if(Number < node->data) {
        if(node->left != NULL) InsertNode(node->left, Number);
        else node->left = CreateNode(Number);
    }
}


Node* searchEmptyNode(Node* Tree) {
    if(Tree == NULL) return NULL;
    if(Tree->left != NULL) return searchEmptyNode(Tree->left);
    else return Tree;
}


Node* removeNode(Node* Tree, int data) {
    Node* tempNode;
    printf("Current: %s\n",(char *)Tree);
    
    if(Tree == NULL) printf("해당 노드를 찾을 수 없습니다.\n");
    else if(Tree->data > data) Tree->left = removeNode(Tree->left, data); 
    else if(Tree->data < data) Tree->right = removeNode(Tree->right, data);
    else {
        if(Tree->left != NULL && Tree->right != NULL) {
            tempNode = searchEmptyNode(Tree->right);
            Tree->data = tempNode->data;
            Tree->right = removeNode(Tree->right, tempNode->data);
        } else {
            tempNode = Tree;
            if(Tree->left == NULL) Tree = Tree->right;
            else if(Tree->right == NULL) Tree = Tree->left;
            free(tempNode);
        }
    }
    
    return Tree;
}


//Destroy the TREE
void DestroyTree(Node* root) {
    if(root == NULL) return;

    //Destory the left Node
    DestroyTree(root->left);

    //Destroy the right Node
    DestroyTree(root->right);

    //Destroy the Root Node
    free(root);
}

void PreOrderPrintTree(Node *node) {
    if(node == NULL) return;

    //Prints the value of Parents(or Current) Node
    printf("%d ", node->data);

    //Prints left Node
    PreOrderPrintTree(node->left);

    //Prints right Node
    PreOrderPrintTree(node->right);
}

void InOrderPrintTree(Node *node) {
    if(node == NULL) return;

    //Prints left Node
    InOrderPrintTree(node->left);

    //Prints the value of Parents(or Current) Node
    printf("%d ", node->data);

    //Prints right Node
    InOrderPrintTree(node->right);

}

void PostOrderPrintTree(Node *node) {
    if(node == NULL) return;

    //Prints left Node
    PostOrderPrintTree(node->left);

    //Prints right Node
    PostOrderPrintTree(node->right);

    //Prints the value of Parents(or Current) Node
    printf("%d ", node->data);
}



// Additional Functions.
void cmdMainScreenFunc(Node *default_root) {
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

void cmdSelectFunc(Node *default_root) {
    int op, Number;
    char op2;
    
    fflush(stdin);
    scanf("%d", &op);
    switch(op) {
        case 1:
            fflush(stdin);
            printf("Input Value to Add: ");
            scanf("%d", &Number);
            printf("\nop: %d, Number:%d \n",op,Number); //TEST CODE
            if(default_root == NULL) {printf("default_root is NUlL\n"); default_root = CreateNode(Number); }
            else {printf("default_root is NUlL\n"); InsertNode(default_root, Number); }
            break;
        case 2:
            fflush(stdin);
            printf("Input Value to Remove: ");
            scanf("%d", &Number);
            printf("\nop: %d, Number:%d \n",op,Number); //TEST CODE
            default_root = removeNode(default_root, Number);
            break;
        case 3:
            printf("\nop: %d, Number:%d \n",op,Number); //TEST CODE
            printf("\n");
            PreOrderPrintTree(default_root);
            break;
        case 4:
            printf("\nop: %d, Number:%d \n",op,Number); //TEST CODE
            printf("\n");
            InOrderPrintTree(default_root);
            break;
        case 5:
            printf("\nop: %d, Number:%d \n",op,Number); //TEST CODE
            printf("\n");
            PostOrderPrintTree(default_root);
            break;
        case 6:
            printf("\nop: %d, Number:%d \n",op,Number); //TEST CODE
            printf("Are you sure to Destroy the all of the Tree?(y/N): ");
            DestroyTree(default_root);
            break;
        case 42:
                DestroyTree(default_root);
                printf("Good bye\n");
                exit(1);
                return;
            break;
        default:
            printf("\nop: %d, Number:%d \n",op,Number); //TEST CODE
            cmdErrorHandlingFunc("Wrong Operation");

    }
}
void cmdErrorHandlingFunc(char* errMessage) {
    printf("Error: %s\n",errMessage);
}