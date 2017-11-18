#ifndef LAB_3_AVL_TREE_H
#define LAB_3_AVL_TREE_H
#include <stdio.h>
#include <stdlib.h>

typedef int (*compare_f)(void* a, void* b);
typedef void (*print_f)(void* data);
typedef void (*delete_f)(void* data);
typedef void* (*copy_f)(void* data);

typedef struct node {
    void* data;
    int height;
    struct node *left;
    struct node *right;
} NODE;

typedef struct {
    NODE* root;
    compare_f cmp;
    print_f prnt;
    delete_f del;
    copy_f cp;
} avl_tree;

//initialization
void init_tree(avl_tree* tree, compare_f cmp, print_f prnt, delete_f del, copy_f cp);
//creating new node
static void new_node(NODE** tmp, void* data);
//insert data into tree
static void insert_helper(NODE** node, void* key, compare_f cmp);
//wrapping function for insert
void insert(avl_tree* tree, void* key);
//service functions for tree rotations
static int max(int a, int b);
static int height(NODE* tmp);
static int balance_factor(NODE** node);
//rotate functions
static void rotate_right(NODE** node);
static void rotate_left(NODE** node);
//delete selected data from tree
static void delete_helper(NODE** node, NODE** parent, void* key, compare_f cmp, delete_f del, copy_f cp);
//wrapping function for delete
void delete(avl_tree* tree, void* key);
//service function for delete
static NODE* get_right_min(NODE* node);
//traversal functions and search in tree
void search(avl_tree* tree, void* data);
static NODE* search_helper(NODE* node, void* key);
static void preorder_traversal_helper(NODE* node, print_f prnt);
static void inorder_traversal_helper(NODE* node, print_f prnt);
static void postorder_traversal_helper(NODE* node, print_f prnt);
void preorder_traversal(avl_tree* tree);
void inorder_traversal(avl_tree* tree);
void postorder_traversal(avl_tree* tree);

#endif //LAB_3_AVL_TREE_H
