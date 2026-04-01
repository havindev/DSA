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
    TreePrintInOrder(tree);

    // Câu 3: giá trị lớn nhất
    int maxVal = TreeMax(tree->root);
    printf("Max value in BST = %d\n", maxVal);

    return 0;
}