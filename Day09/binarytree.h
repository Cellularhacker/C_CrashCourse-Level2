/*
* 2016-07-15 ~ 2015-08-11
* 이진트리
* basic.h
* Cellularhacker
* GNU General Public License v3.0
*/
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
    struct treeNode *left;
    struct treeNode *right;
    int data;
} Node;

Node* CreateNode(int Number);
void InsertNode(Node *root, int Number);
void DestroyNode(Node *root, int data);
void DestroyTree(Node *root);
void PreOrderPrintTree(Node *node);
void InOrderPrintTree(Node *node);
void PostOrderPrintTree(Node *node);


#endif