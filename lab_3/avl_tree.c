#include "avl_tree.h"

void init_tree(avl_tree* tree, compare_f cmp, print_f prnt, delete_f del, copy_f cp) {
    tree->root = NULL;
    tree->cmp = cmp;
    tree->prnt = prnt;
    tree->del = del;
    tree->cp = cp;
}

void new_node(NODE** tmp, void* data) {
    *tmp = malloc(sizeof(NODE));
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
    if (cmp(key, (*node)->data) == 1)
        insert_helper(&(*node)->right, key, cmp);
    else if (cmp(key, (*node)->data) == 0)
        insert_helper(&(*node)->left, key, cmp);
    //update height for node after insert
    (*node)->height = max(height((*node)->left), height((*node)->right)) + 1;

    //get balance
    int balance = balance_factor(&(*node));

    //consider 4 cases of rotation
    //left left
    if (balance > 1 && cmp(key, (*node)->left->data) == 0)
        rotate_right(&(*node));
    //left right
    if (balance > 1 && cmp(key, (*node)->left->data) == 1) {
        rotate_left(&(*node)->left);
        rotate_right(&(*node));
    }
    //right right
    if (balance < -1 && cmp(key, (*node)->right->data) == 1)
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

    //rotate
    (*node)->right = t2;
    y->left = *node;

    //new heights
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

NODE* get_right_min(NODE* node) {
    //get minimum in a right subtree
    NODE* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
void delete(avl_tree* tree, void* key) {
    delete_helper(&tree->root, &tree->root, key, tree->cmp, tree->del, tree->cp);
}

void delete_helper(NODE** node, NODE** parent, void* key, compare_f cmp, delete_f del, copy_f cp) {
    if (*node == NULL)
        return;

    if (cmp(key, (*node)->data) == 0)
        delete_helper(&(*node)->left, &(*node), key, cmp, del, cp);
    else if (cmp(key, (*node)->data) == 1)
        delete_helper(&(*node)->right, &(*node), key, cmp, del, cp);
    else {
        if ((*node)->left == NULL && (*node)->right == NULL) {
            del((*node)->data);
            free(*node);
            *node = NULL;
            return;
        }
        //parent's pointer to child that we want to delete reallocate to childes of our child
        else if ((*node)->left != NULL && (*node)->right == NULL) {
            NODE* tmp = (*node)->left;
            del((*node)->data); //this is for void*
            if ((*parent)->right == (*node)) {
                free(*node);
                (*parent)->right = tmp;
            }
            else if ((*parent)->left == (*node)) {
                free(*node);
                (*parent)->left = tmp;
            }
            //if we delete root
            else {
                rotate_right(&(*node));
                free((*node)->right);
                (*node)->right = NULL;
            }
            return;
        }
        else if ((*node)->right != NULL && (*node)->left == NULL) {
            NODE* tmp = (*node)->right;
            del((*node)->data); //this is for void*
            if ((*parent)->right == (*node)) {
                free(*node);
                (*parent)->right = tmp;
            }
            else if ((*parent)->left == (*node)) {
                free(*node);
                (*parent)->left = tmp;
            }
            //if we delete root
            else {
                rotate_right(&(*node));
                free((*node)->left);
                (*node)->left = NULL;
            }
            return;
        }
        else if ((*node)->right != NULL && (*node)->left != NULL) {
            //get inorder successor
            NODE* tmp = get_right_min((*node)->right);
            (*node)->data = cp(tmp->data);
            delete_helper(&(*node)->right, &(*node), tmp->data, cmp, del, cp);
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

NODE* search_helper(NODE* node, void* key) {
    if (node == NULL || node->data == key)
        return node;
    if (key > node->data)
        return search_helper(node->right, key);
    else
        return search_helper(node->left, key);
}

void search(avl_tree* tree, void* data) {
    search_helper(tree->root, data);
}

void preorder_traversal_helper(NODE* node, print_f prnt) {
    if (node != NULL) {
        prnt(node->data);
        preorder_traversal_helper(node->left, prnt);
        preorder_traversal_helper(node->right, prnt);
    }
}

void inorder_traversal_helper(NODE* node, print_f prnt) {
    if (node != NULL) {
        inorder_traversal_helper(node->left, prnt);
        prnt(node->data);
        inorder_traversal_helper(node->right, prnt);
    }
}

void postorder_traversal_helper(NODE* node, print_f prnt) {
    if (node != NULL) {
        postorder_traversal_helper(node->left, prnt);
        postorder_traversal_helper(node->right, prnt);
        prnt(node->data);
    }
}

void preorder_traversal(avl_tree* tree) {
    preorder_traversal_helper(tree->root, tree->prnt);
}

void inorder_traversal(avl_tree* tree) {
    inorder_traversal_helper(tree->root, tree->prnt);
}

void postorder_traversal(avl_tree* tree) {
    postorder_traversal_helper(tree->root, tree->prnt);
}
