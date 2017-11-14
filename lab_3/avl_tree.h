#ifndef LAB_3_AVL_TREE_H
#define LAB_3_AVL_TREE_H

typedef int (*compare_f)(void* a, void* b);

typedef struct node {
    void* data;
    int height;
    struct node *left;
    struct node *right;
} NODE;

typedef struct {
    NODE* root;
    compare_f cmp;
} avl_tree;

void init_tree(avl_tree* tree, compare_f cmp);
void new_node(NODE** tmp, void* data);
void insert_helper(NODE** node, void* key, compare_f cmp);
void insert(avl_tree* tree, void* key);
NODE* search(NODE* node, void* key);
int max(int a, int b);
int height(NODE* tmp);
void rotate_right(NODE** node);
void rotate_left(NODE** node);
int balance_factor(NODE** node);
NODE* get_right_min(NODE* node);
void delete(NODE** node, NODE** parent, int key);
void inorder(NODE* node);

#endif //LAB_3_AVL_TREE_H
