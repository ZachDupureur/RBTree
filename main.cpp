#include "header.h"
int main () {
    Node A(9);
    Tree newTree(&A);

    insert(&newTree, 18);
    insert(&newTree, 7);
    insert(&newTree, 14);
    insert(&newTree, 17);
    insert(&newTree, 45);
    insert(&newTree, 26);
    insert(&newTree, 35);
    insert(&newTree, 50);
    insert(&newTree, 2);
    insert(&newTree,1);
    insert(&newTree, 60);
    printTree(newTree.root, 0);



}

/****************************** TESTING BELOW ****************************************

                                        60(RED) <

                              50(BLACK) <

                    45(RED) <

                              35(BLACK) <

          26(BLACK) <

                    18(BLACK) <

17(BLACK) <

                    14(BLACK) <

          9(BLACK) <

                              7(RED) <

                    2(BLACK) <

                              1(RED) <

Process finished with exit code 0

 */