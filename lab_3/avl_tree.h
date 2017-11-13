#ifndef LAB_3_AVL_TREE_H
#define LAB_3_AVL_TREE_H

typedef struct node {
    int data;
    int height;
    struct node *left;
    struct node *right;
} NODE;

//functions inside struct?
typedef struct {
    NODE* root;
} avl_tree;

void new_node(NODE** tmp, int data);
NODE* search(NODE* node, int key);
int max(int a, int b);
int height(NODE* tmp);
void rotate_right(NODE** node);
void rotate_left(NODE** node);
int balance_factor(NODE** node);
void insert(NODE** node, int key);
NODE* get_right_min(NODE* node);
void delete(NODE** node, NODE** parent, int key);
void inorder(NODE* node);

#endif //LAB_3_AVL_TREE_H
