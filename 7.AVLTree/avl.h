#ifndef AVL_H
#define AVL_H

// 1. Data structure
// STRUCT Node:
//     INTEGER key
//     Node POINTER left
//     Node POINTER right
//     INTEGER height
// END STRUCT

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
    int height;
} Node;


// 2. Prototype
Node *avl_create_node(int key);

int avl_height(Node *n);
int avl_max(int a, int b);
int avl_get_balance(Node *n);

Node *avl_right_rotate(Node *y);
Node *avl_left_rotate(Node *x);
Node *avl_insert(Node *root, int key);

void avl_preorder(Node *root);
void avl_inorder(Node *root);

void avl_print_tree(Node *root, int level);
void avl_free(Node *root);

#endif
