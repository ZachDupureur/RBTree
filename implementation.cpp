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
                         newNode->color = true; // New node must be red
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
                             newNode->color = true; // New node must be red
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

Node::Node() { // default constructor
    data = 0;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    color = false;
}

Node::Node(double i) { // Parameter constructor
    right = nullptr;
    left = nullptr;
    parent = nullptr;
    data = i;
    color = false;
}

void rotateL(Tree *t, Node *root) {  // FIXME
    Node * A = root->right;
    Node * B = A->left;

    A->left = root;
    root->parent = A;
    root->right = B;

    if (t->root == root) {
        t->root = A;
    }

}

void rotateR (Tree * t, Node * root) {
    Node * A = root->left;
    Node * B = A->right;

    A->right = root;
    root->parent = A;
    root-> left = B;

    if (t->root == root) {
        t->root = A;
    }
}

void fixColors(Tree *t, Node *root) {

    Node * uncle = nullptr;
    Node * temp = root;

    if (root == root->parent->left) {
        uncle = root->parent->right;
    }
    else {
        uncle = root->parent->left;
    }

    if (uncle == nullptr || !uncle->color) {

        while (temp != t->root) {

        }
    }


}

Node &Node::operator = (const Node &rightObj) {
    if (this != &rightObj) {
        this->data = rightObj.data;
        this->right = rightObj.right;
        this->left = rightObj.left;
        this->parent = rightObj.parent;
        this->color = rightObj.color;
    }
    return *this;
}