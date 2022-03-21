/// Created by Zach Dupureur on 3/11/22.

#include "header.h"

 void insert(Tree * t, double key) {
     Node *temp = t->root;
     Node *newNode = new Node(key);
     if (temp == nullptr) { // Tree is empty, make new node root
         t->root = newNode;
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

     fixTree(t,newNode);
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

void rotateL(Tree *t, Node *root) {
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

void fixTree(Tree *t, Node *root) {

    Node* parent = nullptr;
    Node* grandParent = nullptr;
    Node* uncle = nullptr;
    Node* temp = new Node;


    while ((root != t->root) && root->color && root->parent->color) {
        grandParent = root->parent->parent;
        parent = root->parent;


        if (root->parent == grandParent->left) {
            uncle = grandParent->right;

            if (uncle != nullptr && uncle->color) {
                grandParent->color = true;
                parent->color = false;
                uncle->color = false;
                root = grandParent;
            }
            else {
                // New node is right child of parent. Rotate Left
                if (root == parent->right) {
                    rotateL(t, parent);
                    root = parent;
                    parent = root->parent;
                }

                rotateR(t, grandParent);
                temp->color = grandParent->color;
                grandParent->color = parent->color;
                parent->color = temp->color;
                root = parent;
            }
        }

        else {
            uncle = grandParent->left;

            if (uncle != nullptr && uncle->color) {
                grandParent->color = true;
                parent->color = false;
                uncle->color = false;
                root = grandParent;
            }
            else {
                // New node is left child of parent. Rotate Right
                if ( root == parent->left) {
                    rotateL(t, parent);
                    root = parent;
                    parent = root->parent;
                }

                rotateL(t,grandParent);
                temp->color = grandParent->color;
                grandParent->color = parent->color;
                parent->color = temp->color;
                root = parent;
            }
        }
    }

    t->root->color = false;
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