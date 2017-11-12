#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

void new_node(NODE** tmp, int data) {
    //is it right malloc?
    //why not *tmp = malloc(sizeof(NODE*));
    *tmp = malloc(sizeof(NODE)); // why explicit conversion (struct node*)?
    /* NODE* tmp = (NODE*)malloc(sizeof(NODE)); */

    (*tmp)->data = data;
    (*tmp)->height = 1;
    (*tmp)->left = NULL;
    (*tmp)->right = NULL;
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

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(NODE* tmp) {
    if (tmp == NULL)
        return 0;
    return tmp->height;
}

void rotate_right(NODE** node) {
    //malloc for temp NODE inside function?
    NODE* x = (*node)->left;
    NODE* t2 = x->right;

    //rotate
    (*node)->left = t2;
    x->right = *node;

    //new heights
    (*node)->height = max(height((*node)->left), height((*node)->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    *node = x;
}

void rotate_left(NODE** node) {
    NODE* y = (*node)->right;
    NODE* t2 = y->left;

    (*node)->right = t2;
    y->left = *node;

    (*node)->height = max(height((*node)->left), height((*node)->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    *node = y;
}

int balance_factor(NODE** node) {
    //return balance factor between left and right subtree
    if (*node == NULL)
        return 0;
    return height((*node)->left) - height((*node)->right);
}

void insert(NODE** node, int key) {
    //typical bst insert
    if (*node == NULL) {
        new_node(node, key);
        return;
    }
    if (key < (*node)->data)
        insert(&(*node)->left, key);
    else if (key > (*node)->data)
        insert(&(*node)->right, key);

    //update height for node after insert
    (*node)->height = max(height((*node)->left), height((*node)->right)) + 1;

    //get balance
    int balance = balance_factor(&(*node));

    //consider 4 cases of rotation
    //left left
    if (balance > 1 && key < (*node)->left->data)
        rotate_right(&(*node));
    //left right
    if (balance > 1 && key > (*node)->left->data) {
        rotate_left(&(*node)->left);
        rotate_right(&(*node));
    }
    //right right
    if (balance < -1 && key > (*node)->right->data)
        rotate_left(&(*node));
    //right left
    if (balance < -1 && key < (*node)->right->data) {
        rotate_right(&(*node)->right);
        rotate_left(&(*node));
    }
}

NODE* get_right_min(NODE* node) {
    NODE* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

void delete(NODE** node, int key) {
    if (*node == NULL)
        return;

    if (key < (*node)->data)
        delete(&(*node)->left, key);
    else if (key > (*node)->data)
        delete(&(*node)->right, key);
    else {
        if ((*node)->left == NULL && (*node)->right == NULL) {
            //is it correct free?

            free(*node);
            *node = NULL;
            return;
        }
        else if ((*node)->left != NULL && (*node)->right == NULL) {
            //free memory in this case???

            *node = (*node)->left;
            return;
        }
        else if ((*node)->right != NULL && (*node)->left == NULL) {

            //free memory in this case (example)???
//            NODE tmp = *(*node)->right;
//            free((*node)->right);
//            **node = tmp;

            *node = (*node)->right;
            return;
        }
        else if ((*node)->right != NULL && (*node)->left != NULL) {
            //get inorder successor
            NODE* tmp = get_right_min((*node)->right);
            (*node)->data = tmp->data;
            delete(&(*node)->right, tmp->data);

            return;
        }
    }

    //update height for node after insert
    (*node)->height = max(height((*node)->left), height((*node)->right)) + 1;

    //get balance
    int balance = balance_factor(&(*node));

    //consider 4 cases of rotation
    //left left
    if (balance > 1 && balance_factor(&(*node)->left) >= 0)
        rotate_right(&(*node));
    //left right
    if (balance > 1 && balance_factor(&(*node)->left) < 0) {
        rotate_left(&(*node)->left);
        rotate_right(&(*node));
    }
    //right right
    if (balance < -1 && balance_factor(&(*node)->right) <= 0)
        rotate_left(&(*node));
    //right left
    if (balance < -1 && balance_factor(&(*node)->right) > 0) {
        rotate_right(&(*node)->right);
        rotate_left(&(*node));
    }
}

void inorder(NODE* node) {
    if (node != NULL) {
//        printf("%d ", node->data);
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
//        printf("%d ", node->data);
    }
}
