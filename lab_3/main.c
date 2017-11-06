#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NODE;

NODE* new_node(int data) {
    NODE* temp = malloc(sizeof(*temp)); // why explicit conversion (struct node*)?
    /* NODE* tmp = (NODE*)malloc(sizeof(NODE)); */
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

NODE* insert(NODE* node, int key) {
    if (node == NULL)
        return new_node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

int main() {

    NODE* root = NULL;

    root = insert(root, 50);
    insert(root, 25);
    insert(root, 45);
    insert(root, 15);

    printf("hey\n");

    return 0;
}