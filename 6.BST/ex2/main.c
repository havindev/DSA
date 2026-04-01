#include "bst.h"
#include <stdio.h>

int main(void)
{
    Tree *tree = CreateTree();
    if (!tree)
        return 1;

    TreeInsert(tree, 7);
    TreeInsert(tree, 4);
    TreeInsert(tree, 9);
    TreeInsert(tree, 1);
    TreeInsert(tree, 6);
    TreeInsert(tree, 8);
    TreeInsert(tree, 10);

    printf("Inorder: \n");
    TreePrintInorder(tree); // expected: 1 4 6 7 8 9 10

    // Câu 2: số lá
    int leaves = TreeCountLeaves(tree->root);
    printf("Tree leaves = %d\n", leaves);

    return 0;
}
