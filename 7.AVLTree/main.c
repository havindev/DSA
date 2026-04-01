#include <stdio.h>
#include "avl.h"

int main(void)
{
    Node *root = NULL;

    int keys[] = {30, 15, 18, 10, 16, 7, 8};
    int n = sizeof(keys) / sizeof(keys[0]);

    int i;
    for (i = 0; i < n; i++)
    {
        printf("Insert %d\n", keys[i]);
        root = avl_insert(root, keys[i]);
        printf("  Inorder:  ");
        avl_inorder(root);
        printf("\n");
        printf("  Preorder: ");
        avl_preorder(root);
        printf("\n");
        printf("--------------\n");
    }
    avl_print_tree(root, 0);
    avl_free(root);
    return 0;
}
