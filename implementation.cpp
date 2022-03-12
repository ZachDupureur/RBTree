/// Created by Zach Dupureur on 3/11/22.

#include "header.h"

 void insert(Node* root, double key) {
     Node *temp = root;
     Node *newNode = new Node(key);
     if (temp == nullptr) { // Tree is empty, make new node root
         root = newNode;
         newNode->color = false; // Root must be black
     }
     else { // Tree not empty
         while (temp != nullptr) { // Search for leaf
             if (temp->data == newNode->data) { // Duplicate data
                 std::cout << "Cannot insert. Duplicate data.\n";
                 break;
             }
             else {
                 if (newNode->data < temp->data) { // If smaller go to left
                     if (temp->left == nullptr) { // Add node if nullptr
                         temp->left = newNode;
                         newNode->parent = temp; // Assign parent
                         newNode->color = false; // New leaf must be black
                         temp = nullptr;
                     }
                     else {
                         temp = temp->left;
                     }
                 }
                 else {
                     if (newNode->data > temp->data) { // If larger go to right
                         if (temp->right == nullptr) { // Add node if nullptr
                             temp->right = newNode;
                             newNode->parent = temp; // Assign parent
                             newNode->color = false; // New leaf must be black
                             temp = nullptr;
                         }
                         else {
                             temp = temp->right;
                         }
                     }
                 }
             }
         }
     }
 }

int getHeight(Node *root) {
    if (root == nullptr) {
        return 0;
    }
    else {
        int x = getHeight(root->left) + 1;
        int y = getHeight(root->right) + 1;
        return x>y ? x:y;
    }
}

void switchColor (Node* s) {
    if (s->color) {
        s->color = false;
    }
    else {
        s->color = true;
    }
}

Node::Node(double i) {
    right = nullptr;
    left = nullptr;
    parent = nullptr;
    data = i;
    color = false;
}