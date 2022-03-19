/// Created by Zach Dupureur on 3/11/22.
/// Decided to restructure my binary tree this time.


#ifndef RBTREE_HEADER_H
#define RBTREE_HEADER_H

#include <iostream>

class Node {
public:
    Node();
    double data = 0;
    Node * left = nullptr;
    Node * right = nullptr;
    Node * parent = nullptr; // Need parent to find uncle
    bool color = false; // False is black, true is red
    explicit Node(double i);
    Node & operator = (const Node &rightObj); // Changing operator for easier swap
};

class Tree { // Class to hold tree
public:
    Node * root;
    Tree() {
        root = nullptr;
    }
    explicit Tree(Node* root) {
        this->root = root;
    }
};

void insert(Node* root, double key);
void rotateL(Tree *t, Node* root);
void rotateR(Tree *t, Node* root);
void fixColors(Tree *t, Node* root);
int getHeight(Node* root); // Get height of tree

#endif //RBTREE_HEADER_H
