#include "header.h"
int main () {
    Node A(45);
    Tree newTree(&A);

    insert(&newTree, 45);
    insert(&newTree, 55);
    insert(&newTree, 65);
    insert(&newTree, 75);


}