#include "avl_tree.h"

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
    if (data != NULL) {
        int a = *(int*)data;
        printf("%d ", a);
    }
}

void* copy(int data) {
    int* mem = malloc(sizeof(int));
    *mem = data;
    return mem;
}

void* copy_int(void* data) {
    int* mem = malloc(sizeof(int));
    *mem = *(int*)data;
    return mem;
}

void del_int(void* data) {
    free(data);
}

int main() {

    avl_tree a;
    init_tree(&a, compare_int, print_tree, del_int, copy_int);

    //insert and rotate test
    insert(&a, copy(10));
    insert(&a, copy(20));
    insert(&a, copy(30));
    insert(&a, copy(40));
    insert(&a, copy(50));
    insert(&a, copy(25));

    inorder_traversal(&a);
    printf("\n");

    //delete test
    delete(&a, copy(10));
    delete(&a, copy(20));
    delete(&a, copy(30));
    delete(&a, copy(40));
    delete(&a, copy(50));
    delete(&a, copy(25));

    inorder_traversal(&a);
    printf("\n");

    return 0;
}