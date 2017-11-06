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

NODE* search(NODE* node, int key) {
    if (node == NULL || node->data == key)
        return node;
//    if (node == NULL) {
//        printf("%d is not found\n", key);
//        return;
//    }
//    else if (node->data == key) {
//        printf("found %d\n", key);
//        return;
//    }
    if (key > node->data)
        return search(node->right, key);
    else
        return search(node->left, key);
}

void delete(NODE* node, int key) {
    NODE* temp = search(node, key);

    if (temp == NULL)
        return;


    if (temp->right == NULL && temp->left == NULL)
        free(temp);

    if (temp->right != NULL || temp->left != NULL) {}
}

void inorder(NODE* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main() {

    NODE* root = NULL;

    root = insert(root, 50);
    insert(root, 25);
    insert(root, 45);
    insert(root, 15);

    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);
//    search(root, 98);
//    search(root, 15);

    return 0;
}