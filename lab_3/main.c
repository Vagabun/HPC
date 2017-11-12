#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

int main() {

    NODE* root = NULL;

    // rotate test
//    insert(&root, 10);
//    insert(&root, 20);
//    insert(&root, 30);
//    insert(&root, 40);
//    insert(&root, 50);
//    insert(&root, 28);

    //delete test
    insert(&root, 9);
    insert(&root, 5);
    insert(&root, 10);
    insert(&root, 0);
    insert(&root, 6);
    insert(&root, 11);
    insert(&root, -1);
    insert(&root, 1);
    insert(&root, 2);

    inorder(root);
    printf("\n");
    delete(&root, 10);
    inorder(root);
    printf("\n");

    return 0;
}