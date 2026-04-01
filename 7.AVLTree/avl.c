#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

// 1. Tạo Node
// FUNCTION avl_create_node(key):
//     n ← allocate memory of size Node
//         PRINT "Memory allocation failed" TO standard error
//         TERMINATE program
//     END IF
//     IF n = NULL THEN
//     n.key ← key
//     n.left ← NULL
//     n.right ← NULL
//     n.height ← 1
//     RETURN n
// END FUNCTION

Node *avl_create_node(int key)
{
    Node *n = malloc(sizeof(Node));
    if (n == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;
    return n;
}

int avl_height(Node *n)
{
    return (n == NULL) ? 0 : n->height;
}

int avl_max(int a, int b)
{
    return (a > b) ? a : b;
}

int avl_get_balance(Node *n)
{
    return (n != NULL) ? avl_height(n->left) - avl_height(n->right) : 0;
}

// 2. Right Rotate
// FUNCTION avl_right_rotate(y):
//     x ← y.left
//     T2 ← x.right
// Thực hiện rotation
//     x.right ← y
//     y.left ← T2
// Cập nhật chiều cao của y
//     y.height ← avl_max(avl_height(y.left),avl_height(y.right)) + 1
// Cập nhật chiều cao của x
//     x.height ← avl_max(avl_height(x.left),avl_height(x.right)) + 1
//     RETURN x
// END FUNCTION

Node *avl_right_rotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    // Thực hiện rotation
    x->right = y;
    y->left = T2;
    // Cập nhật chiều cao của y
    y->height = avl_max(avl_height(y->left), avl_height(y->right)) + 1;
    // Cập nhật chiều cao của x
    x->height = avl_max(avl_height(x->left), avl_height(x->right)) + 1;
    return x;
}
// 3. Left Rotate
// FUNCTION avl_left_rotate(x):
//     y ← x.right
//     T2 ← y.left
// Thực hiện rotation
//     y.left ← x
//     x.right ← T2
// Cập nhật chiều cao của x
//     x.height ← avl_max(avl_height(x.left), avl_height(x.right)) + 1
// Cập nhật chiều cao của y
//     y.height ← avl_max(avl_height(y.left),avl_height(y.right)) + 1
//     RETURN y
// END FUNCTION

Node *avl_left_rotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    // Thực hiện rotation
    y->left = x;
    x->right = T2;
    // Cập nhật chiều cao của x
    x->height = avl_max(avl_height(x->left), avl_height(x->right)) + 1;
    // Cập nhật chiều cao của y
    y->height = avl_max(avl_height(y->left), avl_height(y->right)) + 1;
    return y;
}
// 4. INSERT
// FUNCTION avl_insert(root, key):
//     // Trường hợp cây rỗng → tạo node mới
//     IF root = NULL THEN
//         RETURN avl_create_node(key)
//     END IF
//     // Quyết định chèn vào bên trái hoặc bên phải
//     IF key < root.key THEN
//         root.left ← avl_insert(root.left, key)
//     ELSE IF key > root.key THEN
//         root.right ← avl_insert(root.right, key)
//     ELSE
//         // Key đã tồn tại, không chèn trùng
//         RETURN root
//     END IF
//     // Cập nhật lại chiều cao của node hiện tại
//     root.height ← 1 + avl_max(avl_height(root.left),avl_height(root.right))
//     // Tính Balance Factor
//     balance ← avl_get_balance(root)
//     // --- Xử lý các trường hợp mất cân bằng ---
//     // CASE 1: Left-Left
//     IF balance > 1 AND key < root.left.key THEN
//         RETURN avl_right_rotate(root)
//     END IF
//     // CASE 2: Right-Right
//     IF balance < −1 AND key > root.right.key THEN
//         RETURN avl_left_rotate(root)
//     END IF
//     // CASE 3: Left-Right
//     IF balance > 1 AND key > root.left.key THEN
//         root.left ← avl_left_rotate(root.left)
//         RETURN avl_right_rotate(root)
//     END IF
//     // CASE 4: Right-Left
//     IF balance < −1 AND key < root.right.key THEN
//         root.right ← avl_right_rotate(root.right)
//         RETURN avl_left_rotate(root)
//     END IF
//     // Trả về node sau khi chèn và cân bằng
//     RETURN root
// END FUNCTION

Node *avl_insert(Node *root, int key)
{
    // Trường hợp cây rỗng → tạo node mới
    if (root == NULL)
    {
        return avl_create_node(key);
    }
    // Quyết định chèn vào bên trái hoặc bên phải
    if (key < root->key)
    {
        root->left = avl_insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = avl_insert(root->right, key);
    }
    else
    {
        // Key đã tồn tại, không chèn trùng
        return root;
    }
    // Cập nhật lại chiều cao của node hiện tại
    root->height = avl_max(avl_height(root->left), avl_height(root->right)) + 1;
    // Tính Balance Factor
    int balance = avl_get_balance(root);
    // --- Xử lý các trường hợp mất cân bằng ---
    // CASE 1: Left-Left
    if (balance > 1 && key < root->left->key)
    {
        return avl_right_rotate(root);
    }
    // CASE 2: Right-Right
    if (balance < -1 && key > root->right->key)
    {
        return avl_left_rotate(root);
    }
    // CASE 3: Left-Right
    if (balance > 1 && key > root->left->key)
    {
        root->left = avl_left_rotate(root->left);
        return avl_right_rotate(root);
    }
    // CASE 4: Right-Left
    if (balance < -1 && key < root->right->key)
    {
        root->right = avl_right_rotate(root->right);
        return avl_left_rotate(root);
    }
    // Trả về node sau khi chèn và cân bằng
    return root;
    return 0;
}
// 5. Traverse

// 5.1 Node → Left → Right
// FUNCTION avl_preorder(root):
//     IF root ≠ NULL THEN
//         PRINT root.key
//         avl_preorder(root.left)
//         avl_preorder(root.right)
//     END IF
// END FUNCTION
void avl_preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        avl_preorder(root->left);
        avl_preorder(root->right);
    }
}

// 5.2 Left → Node → Right (ASC)
// FUNCTION avl_inorder(root):
//     IF root ≠ NULL THEN
//         avl_inorder(root.left)
//         PRINT root.key
//         avl_inorder(root.right)
//     END IF
// END FUNCTION
void avl_inorder(Node *root)
{
    if (root != NULL)
    {
        avl_inorder(root->left);
        printf("%d ", root->key);
        avl_inorder(root->right);
    }
}

void avl_print_tree(Node *root, int level)
{
    int i;
    if (root != NULL)
    {
        avl_print_tree(root->right, level + 1);
        for (i = 0; i < level; i++)
        {
            printf("    ");
        }
        printf("%d (h = %d,bf: %d)\n", root->key, root->height, avl_get_balance(root));
        avl_print_tree(root->left, level + 1);
    }
}

// 5.3 FREE MEMORY
// FUNCTION avl_free(root):
//     IF root = NULL THEN
//         RETURN
//     END IF
//     avl_free(root.left)
//     avl_free(root.right)
//     DEALLOCATE memory at root
// END FUNCTION

void avl_free(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    avl_free(root->left);
    avl_free(root->right);
    free(root);
}
