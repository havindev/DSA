#pragma one

// STRUCT Node
//     INTEGER value                // scalar data stored at this node
//     Node POINTER left            // reference to the left child node
//     Node POINTER right           // reference to the right child node
// END STRUCT
typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

// STRUCT Tree
//     Node POINTER root        // reference to the root node of the tree
// END STRUCT
typedef struct Tree
{
    Node *root;
} Tree;

// Create structures
Node *CreateNode(int value);
Tree *CreateTree(void);

// Basic BST operations
int TreeInsert(Tree *tree, int value);
int TreeFind(const Tree *tree, int value);

// DFS traversals
void InOrderTraverse(const Node *node);
void PreOderTraverse(const Node *node);
void PostOrderTraverse(const Node *node);

// Print wrapper functions
void TreePrintInOrder(const Tree *tree);
void TreePrintPreOrder(const Tree *tree);
void TreePrintPostOrder(const Tree *tree);

// BFS traversal
void TreePrintBFS(const Tree *tree);