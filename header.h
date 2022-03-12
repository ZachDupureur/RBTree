/// Created by Zach Dupureur on 3/11/22.
/// Decided to restructure my binary tree this time.


#ifndef RBTREE_HEADER_H
#define RBTREE_HEADER_H

#include <iostream>

class Node {
public:
    double data = 0;
    Node * left = nullptr;
    Node * right = nullptr;
    explicit Node(double i);
};


void insert(Node* root, double key);

#endif //RBTREE_HEADER_H
