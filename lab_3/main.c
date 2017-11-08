#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} NODE;

void new_node(NODE** tmp, int data) {
    //is it right malloc?
    //why not *tmp = malloc(sizeof(NODE*));
    *tmp = (NODE*)malloc(sizeof(NODE)); // why explicit conversion (struct node*)?
    /* NODE* tmp = (NODE*)malloc(sizeof(NODE)); */

    (*tmp)->data = data;
    (*tmp)->left = NULL;
    (*tmp)->right = NULL;
//    free(*tmp);
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

void insert(NODE** node, int key) {
    if (*node == NULL) {
        new_node(node, key);
        return;
    }
    if (key < (*node)->data)
        insert(&(*node)->left, key);
    else if (key > (*node)->data)
        insert(&(*node)->right, key);
}

// pass search as a parameter?
void delete(NODE** node, int key) {

    if (*node == NULL)
        return;

    if (key < (*node)->data)
        delete(&(*node)->left, key);
    else if (key > (*node)->data)
        delete(&(*node)->right, key);
    else {
        if ((*node)->left == NULL && (*node)->right == NULL) {
            free(*node);
            *node = NULL;

            //is it correct free?
            return;
        }
        else if ((*node)->left != NULL && (*node)->right == NULL) {
            NODE* tmp = (*node)->left;
            *node = tmp;
            free((*node)->left);
            (*node)->left = NULL;

            return;
        }
        else if ((*node)->right != NULL && (*node)->left == NULL) {
            NODE* tmp = (*node)->right;
            *node = tmp;
            free((*node)->right);
            (*node)->right = NULL;
//            free((*node)->right);
            return;
        }
    }

//    return node;
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

//    root = insert(root, 50);
//    insert(root, 25);
//    insert(root, 45);
//    insert(root, 15);
//
//    insert(root, 30);
//    insert(root, 20);
//    insert(root, 40);
//    insert(root, 70);
//    insert(root, 60);
//    insert(root, 80);
//
//    inorder(root);
//    search(root, 98);
//    search(root, 15);

    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    inorder(root);
    printf("\n");

    delete(&root, 20);
    inorder(root);
    printf("\n");

    delete(&root, 30);
    inorder(root);
    printf("\n");

//    printf("\n");
//
//    inorder(root);

//    inorder(root);
//    printf("\n");
//
//    delete(root, 30);
//
//    inorder(root);
//    printf("\n");

    return 0;
}