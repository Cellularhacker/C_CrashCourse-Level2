#include "binarytree.h"

//Create A Node for New Tree
Node* CreateNode(int Number) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->Left = NULL;
    newNode->Right = NULL;
    newNode->data = Number;

    return newNode;
}

//Insert A Value in A Tree
void InsertNoode(Node *node, int Number) {
     if (newNode->Data > Tree->Data)
     {
         if (Tree->Right != NULL) insertNode(Tree->Right, newNode);
         else Tree->Right = newNode;
     }
     else if (newNode->Data < Tree->Data)
    {
         if (Tree->Left != NULL) insertNode(Tree->Left, newNode);
         else Tree->Left = newNode;
     }
}


Node* searchEmptyNode(Node* Tree)
{
    if (Tree == NULL) return NULL;
    if (Tree->Left != NULL) return searchEmptyNode(Tree->Left);
    else return Tree;
}


Node* removeNode(Node* Tree, int data)
{
    Node* tempNode;
 
    if (Tree == NULL) printf("해당 노드를 찾을 수 없습니다.\n");
    else if (Tree->Data > data) Tree->Left = removeNode(Tree->Left, data);
    else if (Tree->Data < data) Tree->Right = removeNode(Tree->Right, data);
    else
    {
        if (Tree->Left != NULL && Tree->Right != NULL)
        {
            tempNode = searchEmptyNode(Tree->Right);
            Tree->Data = tempNode->Data;
            Tree->Right = removeNode(Tree->Right, tempNode->Data);
        }
        else
        {
            tempNode = Tree;
            if (Tree->Left == NULL) Tree = Tree->Right;
            else if (Tree->Right == NULL) Tree = Tree->Left;
            free(tempNode);
        }
    }
 
    return Tree;
}

//Destroy the Node
void DestroyNode(Node *root, int data) {
    TreeNode *parent, *child, *successor, *successor_p, *target;
    
    parent = NULL; //Parent Node's Pointer
    target = *root; //Child Node's Pointer with current Parent Node. 
    
    //Searching Node which has that you want to destroy from the tree.
    while(target != NULL && target->data != data){
        parent = target;
        target = (data < target->data) ? target->left : target->right;
    }
    
    if(t == NULL){ //The data what you want destroy doesn't exist.
        printf("해당 값을 찾을 수 없습니다.\n");
        return;
    }
    //In first case: Current node is terminal.
    if(target->left == NULL && target->right == NULL){
        if(parent != NULL) {
            if(parent->left == target) parent->left = NULL; //In case of left is the one.
            else parent->right = NULL; //In case of right is the one.
        } else  *root = NULL; //If Parent node is null, the one is the root one.
    }

    //In second case: Parent node has only one child node.
    else if((target->left==NULL) || (target->right == NULL)) {
        child = (target->left!=NULL) ? target->left : target->right;
        if(parent != NULL){
            if(parent->left ==t) parent->left=child; //Connets Parent node with Child Node
            else parent->right = child;
        } else //If Parent node is null, the one is the root one.
            *root=child;
    }
    //In third case: Parent node has two child node.
    else {
        //Finds successor in subtree from right.
        successor_p = target;
        successor = target->right;
        //Keep moves left to find successor.
        while(successor->left != NULL){
            successor_p = successor;
            successor = successor->left;
        }
        //Connnects successor, Parent and Child.
        if(successor_p->left == successor) successor_p->left = successor->right;
        else successor_p->right = successor->right;
        //후속자가 가진 키값을 현재 노드에 복사
        target->data = successor->data;
        //원래의 후속자 삭제
        target = successor;
    }

    free(target);
}

//Destroy the TREE
void DestroyTree(Node* root) {
    if(root == NULL) return;

    //Destory the Left Node
    DestroyTree(root->left);

    //Destroy the Right Node
    DestroyTree(root->right)

    //Destroy the Root Node
    DestroyNode(root);
}

void PreOrderPrintTree(Node *node) {
    if(node == NULL) return;

    //Prints the value of Parents(or Current) Node
    printf("%d ", node->data);

    //Prints Left Node
    PreOrderPrintTree(node->left);

    //Prints Right Node
    PreOrderPrintTree(node->right);
}

void InOrderPrintTree(Node *node) {
    if(node == NULL) return;

    //Prints Left Node
    InOrderPrintTree(node->left);

    //Prints the value of Parents(or Current) Node
    printf("%d ", node->data);

    //Prints Right Node
    InOrderPrintTree(node->right);

}

void PostOrderPrintTree(Node *Node) {
    if(node == NULL) return;

    //Prints Left Node
    PostOrderPrintTree(node->left);

    //Prints Right Node
    PostOrderPrintTree(node->Right);

    //Prints the value of Parents(or Current) Node
    printf("%d ", node->data);
}