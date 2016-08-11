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

void InsertNode(Node *root, int Number) {
    /*
    if(Number > node->data) {
        if(node->right != NULL) InsertNode(node->right, Number);
        else node->right = newNode;
    } else if(Number < node->data) {
        if(node->left != NULL) InsertNode(node->left, Number);
        else node->left = newNode;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    */
    //삽입연산 함수
//key를 이진 탐색 트리 root에 삽입한다.
//key가 이미 root안에 있으면 삽입되지 않는다.

    Node *parent, *target;  //p는 부모노드, t는 현재노드
    Node *newNode;  //n은 새로운 노드
    target = root;
    parent = NULL;

    //탐색을 먼저 수행
    while(target != NULL) {
        if(Number == target->data) {
            printf("이미 트리에 존재하는 값입니다.\n ");
            return;
        }
        parent = target;
        if(Number < target->data) target = target->left;
        else target = target->right;
    }
    
    //item이 트리안에 없으므로 삽입 가능
    newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) return;
    //데이터 복사
    newNode->data = Number;
    newNode->left = newNode->right = NULL;
    //부모노드와 링크 연결
    if(parent != NULL){
        if(Number < parent->data) parent->left = newNode;
        else parent->right = newNode;
    }
    else root = newNode;  //부모가 없으면 자기자신이 부모가 되라.
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