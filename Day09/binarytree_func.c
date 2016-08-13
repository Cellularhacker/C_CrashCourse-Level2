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

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = Number;

    return newNode;
}


//Insert A Value in A Tree
void InsertNode(Node *node, int Number) {
    if(Number > node->data) { //Inputed value is bigger than Current node's Data.
        if(node->right != NULL) InsertNode(node->right, Number);    //
        else node->right = CreateNode(Number);
    } else if(Number < node->data) { //Inputed value is smaller than Current node's Data.
        if(node->left != NULL) InsertNode(node->left, Number);
        else node->left = CreateNode(Number);
    } else { //Value is already exist.
        printf("값이 이미 존재 합니다!\n");
    }
}


Node* searchEmptyNode(Node* Tree) {
    if(Tree == NULL) return NULL;
    if(Tree->left != NULL) return searchEmptyNode(Tree->left);
    else return Tree;
}


Node* removeNode(Node* Tree, int data) {
    Node* tempNode;
    
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