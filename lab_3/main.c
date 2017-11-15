#include "avl_tree.h"
#include <stdio.h>
#include <stdlib.h>

//long long (or intptr_t) because on a lot of systems sizeof(long long) == sizeof(void*)
//if int -> warning: cast from pointer to integer of different size

int compare_int(void* a, void* b) {
    int i_a = *(int*)a;
    int i_b = *(int*)b;
    if (i_a == i_b)
        return -1;
    if (i_a > i_b)
        return 1;
    else
        return 0;
}

void print_tree(void* data) {
    int a = *(int*)data;
    printf("%d ", a);
}

//any need of this type?
//void* mem_int(void* data) {
//    int* mem = malloc(sizeof(int));
//    *mem = *(int*)data;
//
//    free(mem);
//    return mem;
//}

int* copy(int data) {
    int* mem = malloc(sizeof(int));
    *mem = data;
//    free(mem);
    return mem;
}

void del_int(void* data) {
    free(data);
}

int main() {

    avl_tree a;
    init_tree(&a, compare_int, print_tree, del_int);

    //difference between (int*) and *(int*)???
    //insert and rotate test

    insert(&a, copy(10));
    insert(&a, copy(20));
    insert(&a, copy(10));
    insert(&a, copy(30));
    insert(&a, copy(30));
    insert(&a, copy(40));
    insert(&a, copy(50));
    insert(&a, copy(25));


    //delete test
    insert(&a, copy(9));
    insert(&a, copy(5));
    insert(&a, copy(10));
    insert(&a, copy(0));
    insert(&a, copy(6));
    insert(&a, copy(11));
    insert(&a, copy(-1));
    insert(&a, copy(1));
    insert(&a, copy(2));

    traversal(&a);
    printf("\n");

    delete(&a, copy(10));

    traversal(&a);
    printf("\n");

    return 0;
}