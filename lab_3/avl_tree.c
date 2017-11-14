#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

void init_tree(avl_tree* tree, compare_f cmp, print_f prnt) {
    tree->root = NULL;
    tree->cmp = cmp;
    tree->prnt = prnt;
}

void new_node(NODE** tmp, void* data) {
    //is it right malloc?
    *tmp = malloc(sizeof(NODE));
    (*tmp)->data = malloc(sizeof(void*));

    (*tmp)->data = data;
    (*tmp)->height = 1;
    (*tmp)->left = NULL;
    (*tmp)->right = NULL;
}

void insert_helper(NODE** node, void* key, compare_f cmp) {
    //typical bst insert
    if (*node == NULL) {
        new_node(node, key);
        return;
    }
    if (cmp(key, (*node)->data))
        insert_helper(&(*node)->right, key, cmp);
    else
        insert_helper(&(*node)->left, key, cmp);
                    //    if (key < (*node)->data)
                    //        insert_helper(&(*node)->left, key);
                    //    else if (key > (*node)->data)
                    //        insert_helper(&(*node)->right, key);

    //update height for node after insert
    (*node)->height = max(height((*node)->left), height((*node)->right)) + 1;

    //get balance
    int balance = balance_factor(&(*node));

    //consider 4 cases of rotation
    //left left
    if (balance > 1 && cmp(key, (*node)->left->data) == 0)
        rotate_right(&(*node));
    //left right
    if (balance > 1 && cmp(key, (*node)->left->data)) {
        rotate_left(&(*node)->left);
        rotate_right(&(*node));
    }
    //right right
    if (balance < -1 && cmp(key, (*node)->right->data))
        rotate_left(&(*node));
    //right left
    if (balance < -1 && cmp(key, (*node)->right->data) == 0) {
        rotate_right(&(*node)->right);
        rotate_left(&(*node));
    }
}

void insert(avl_tree* tree, void* key) {
    insert_helper(&tree->root, key, tree->cmp);
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
//
//NODE* get_right_min(NODE* node) {
//    NODE* current = node;
//    while (current->left != NULL) {
//        current = current->left;
//    }
//    return current;
//}
//
//void delete(NODE** node, NODE** parent, int key) {
//    if (*node == NULL)
//        return;
//
//    if (key < (*node)->data)
//        delete(&(*node)->left, &(*node), key);
//    else if (key > (*node)->data)
//        delete(&(*node)->right, &(*node), key);
//    else {
//        if ((*node)->left == NULL && (*node)->right == NULL) {
//            free(*node);
//            *node = NULL;
//            return;
//        }
//        //parent's pointer to child that we want to delete reallocate to childes of our child
//        else if ((*node)->left != NULL && (*node)->right == NULL) {
//            NODE* tmp = (*node)->left;
//            if ((*parent)->right == (*node)) {
////                free((*node)->data); this is for void*
//                free(*node);
//                (*parent)->right = tmp;
//            }
//            else if ((*parent)->left == (*node)) {
//                free(*node);
//                (*parent)->left = tmp;
//            }
//            return;
//        }
//        else if ((*node)->right != NULL && (*node)->left == NULL) {
//            NODE* tmp = (*node)->right;
//            if ((*parent)->right == (*node)) {
////                free((*node)->data); this is for void*
//                free(*node);
//                (*parent)->right = tmp;
//            }
//            else if ((*parent)->left == (*node)) {
//                free(*node);
//                (*parent)->left = tmp;
//            }
//            return;
//        }
//        else if ((*node)->right != NULL && (*node)->left != NULL) {
//            //get inorder successor
//            NODE* tmp = get_right_min((*node)->right);
//            (*node)->data = tmp->data;
//            delete(&(*node)->right, &(*node), tmp->data);
//            return;
//        }
//    }
//
//    //update height for node after insert
//    (*node)->height = max(height((*node)->left), height((*node)->right)) + 1;
//
//    //get balance
//    int balance = balance_factor(&(*node));
//
//    //consider 4 cases of rotation
//    //left left
//    if (balance > 1 && balance_factor(&(*node)->left) >= 0)
//        rotate_right(&(*node));
//    //left right
//    if (balance > 1 && balance_factor(&(*node)->left) < 0) {
//        rotate_left(&(*node)->left);
//        rotate_right(&(*node));
//    }
//    //right right
//    if (balance < -1 && balance_factor(&(*node)->right) <= 0)
//        rotate_left(&(*node));
//    //right left
//    if (balance < -1 && balance_factor(&(*node)->right) > 0) {
//        rotate_right(&(*node)->right);
//        rotate_left(&(*node));
//    }
//}
//
//NODE* search(NODE* node, int key) {
//    if (node == NULL || node->data == key)
//        return node;
////    if (node == NULL) {
////        printf("%d is not found\n", key);
////        return;
////    }
////    else if (node->data == key) {
////        printf("found %d\n", key);
////        return;
////    }
//    if (key > node->data)
//        return search(node->right, key);
//    else
//        return search(node->left, key);
//}
//
void traversal_helper(NODE* node, print_f prnt) {
    if (node != NULL) {
        prnt(node->data);
        traversal_helper(node->left, prnt);
//        printf("%d ", node->data);
        traversal_helper(node->right, prnt);
//        printf("%d ", node->data);
    }
}

void traversal(avl_tree* tree) {
    traversal_helper(tree->root, tree->prnt);
}
