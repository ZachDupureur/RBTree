#include "header.h"
int main () {
    Node A(45);
    Tree newTree(&A);

    insert(newTree.root, 55);
    insert(newTree.root, 65);
    rotateL(&newTree, &A);

}