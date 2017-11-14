#include "avl_tree.h"
#include <stdio.h>
#include <stdlib.h>

//long long (or intptr_t) because on a lot of systems sizeof(long long) == sizeof(void*)
//if int -> warning: cast from pointer to integer of different size
int compare_int(void* a, void* b) {
//    int i_a = (intptr_t*)a;
//    int i_b = (intptr_t)b;
    int i_a = *(int*)(&a);
    int i_b = *(int*)(&b);
    if (i_a == i_b)
        return -1;
    if (i_a > i_b)
        return 1;
    else
        return 0;
}

void print_tree(void* data) {
    int a = *(int*)(&data);
    printf("%d ", a);
}

void del_int(void* data) {
    int i = 1;
    free(data);
}

int main() {

//    int* a = (int*)6;
//    void* m = malloc(sizeof())

    avl_tree a;
    init_tree(&a, compare_int, print_tree, del_int);

    //difference between (int*) and *(int*)???
    //insert and rotate test
    insert(&a, (int*)10);
    insert(&a, (int*)20);
    insert(&a, (int*)30);
//    insert(&a, (int*)40);
//    insert(&a, (int*)50);
//    insert(&a, (int*)25);

    delete(&a, (int*)30);

    traversal(&a);
    printf("\n");


    // rotate and delete test

//    NODE* root = NULL;
//    insert(&root, 30);
//    insert(&root, 10);
//    insert(&root, 20);
//    insert(&root, 28);
//    insert(&root, 40);
//    insert(&root, 50);
//    insert(&root, 60);
//    insert(&root, 70);
//    printf("\n");
//    delete(&root, &root, 60);

    //delete test
//    insert(&root, 9);
//    insert(&root, 5);
//    insert(&root, 10);
//    insert(&root, 0);
//    insert(&root, 6);
//    insert(&root, 11);
//    insert(&root, -1);
//    insert(&root, 1);
//    insert(&root, 2);
//    inorder(root);
//    printf("\n");
//    delete(&root, &root, 10);
//    inorder(root);
//    printf("\n");

    return 0;
}