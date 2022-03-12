/// Created by Zach Dupureur on 3/11/22.

#include "header.h"

 void insert(Node* root, double key) {
     Node *temp = root;
     Node *newNode = new Node(key);
     if (temp == nullptr) { // Tree is empty, make new node root
         root = newNode;
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

Node::Node(double i) {
    right = nullptr;
    left = nullptr;
    data = i;
}
