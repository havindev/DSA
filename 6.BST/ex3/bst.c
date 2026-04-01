#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

//  //  CREATE NODE AND TREE

/*
FUNCTION CREATE_NODE(x : INTEGER) → Node
    // Allocate a new node structure
    N ← allocate memory for a Node

    IF N = NULL THEN
        SIGNAL "Memory allocation failure"
        RETURN NULL
    END IF

    // Initialize fields
    N.value ← x
    N.left  ← NULL
    N.right ← NULL

    RETURN N
END FUNCTION
*/
Node *CreateNode(int value)
{
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
    {
        fprintf(stderr, "Memory allocation failure\n");
        return NULL;
    }
    node->value = value;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

/*
FUNCTION CREATE_TREE() → Tree
    // Allocate a new Tree structure
    T ← allocate memory for a Tree

    IF T = NULL THEN
        SIGNAL "Memory allocation failure"
        RETURN NULL
    END IF

    // Initialize representation
    T.root ← NULL

    RETURN T
END FUNCTION
*/
Tree *CreateTree(void)
{
    Tree *tree = malloc(sizeof(Tree));
    if (tree == NULL)
    {
        fprintf(stderr, "Memory allocation failure\n");
        return NULL;
    }
    tree->root = NULL;
    return tree;
}

//  //  BST INSERT

/*
FUNCTION TREE_INSERT(T : Tree, x : INTEGER) → BOOLEAN
    IF T = NULL THEN
        RETURN FALSE
    END IF

    new ← CREATE_NODE(x)
    IF new = NULL THEN
        RETURN FALSE
    END IF

    // tree is empty
    IF T.root = NULL THEN
        T.root ← new
        RETURN TRUE
    END IF

    current ← T.root
    parent  ← NULL

    // Descend the tree to find insertion point
    WHILE current ≠ NULL DO
        parent ← current

        IF x < current.value THEN
            current ← current.left
        ELSE IF x > current.value THEN
            current ← current.right
        ELSE
            // Duplicate — insertion policy forbids duplicates
            DEALLOCATE new
            RETURN FALSE
        END IF
    END WHILE

    // Insert new node under the parent
    IF x < parent.value THEN
        parent.left ← new
    ELSE
        parent.right ← new
    END IF

    RETURN TRUE
END FUNCTION
*/
int TreeInsert(Tree *tree, int value)
{
    if (tree == NULL)
    {
        return 0;
    }
    Node *new = CreateNode(value);
    if (new == NULL)
    {
        return 0;
    }
    if (tree->root == NULL)
    {
        tree->root = new;
        return 1;
    }
    Node *cur = tree->root;
    Node *par = NULL;
    while (cur != NULL)
    {
        par = cur;
        if (cur->value > value) cur = cur->left;
        else if (cur->value < value) cur = cur->right;
        else {
            free(new);
            return 0;
        }
    }
    if (par->value > value) par->left  = new;
    if (par->value < value) par->right = new;
    return 1;
}

//  //  BST FIND

/*
FUNCTION TREE_FIND(T : Tree, x : INTEGER) → BOOLEAN
    IF T = NULL THEN
        RETURN FALSE
    END IF

    current ← T.root

    WHILE current ≠ NULL DO
        IF x = current.value THEN
            RETURN TRUE
        ELSE IF x < current.value THEN
            current ← current.left
        ELSE
            current ← current.right
        END IF
    END WHILE

    RETURN FALSE
END FUNCTION
 */
int TreeFind(const Tree *tree, int value)
{
    if (tree == NULL)
    {
        return 0;
    }

    Node *cur = tree->root;

    while (cur != NULL)
    {
        if (cur->value == value) return 1;
        else if (cur->value >  value) cur = cur->left;       
        else cur = cur->right;
    }
    return 0;
}

//  //  DFS TRAVERSALS

/*
PROCEDURE INORDER_TRAVERSE(N : Node)
    IF N = NULL THEN
        RETURN
    END IF

    INORDER_TRAVERSE(N.left)
    OUTPUT N.value
    INORDER_TRAVERSE(N.right)
END PROCEDURE
*/
void InOrderTraverse(const Node *node)
{
    if (node == NULL) return;
    InOrderTraverse(node->left);
    printf("%d\n", node->value);
    InOrderTraverse(node->right);
}

/*
PROCEDURE PREORDER_TRAVERSE(N : Node)
    IF N = NULL THEN
        RETURN
    END IF

    OUTPUT N.value             // visit root
    PREORDER_TRAVERSE(N.left)  // then left subtree
    PREORDER_TRAVERSE(N.right) // then right subtree
END PROCEDURE
*/

/*
PROCEDURE POSTORDER_TRAVERSE(N : Node)
    IF N = NULL THEN
        RETURN
    END IF

    POSTORDER_TRAVERSE(N.left)   // left subtree
    POSTORDER_TRAVERSE(N.right)  // right subtree
    OUTPUT N.value               // visit root (after children)
END PROCEDURE
 */

//  //  WRAPPER PRINT FUNCTIONS

/*
PROCEDURE TREE_PRINT_INORDER(T : Tree)
    IF T = NULL OR T.root = NULL THEN
        OUTPUT "(empty)"
        RETURN
    END IF

    INORDER_TRAVERSE(T.root)
    OUTPUT end-of-line
END PROCEDURE
 */
void TreePrintInOrder(const Tree *tree)
{
    if (tree == NULL || tree->root == NULL)
    {
        printf ("Tree Empty");
        return;
    }

    InOrderTraverse(tree->root);
    printf("End of Tree");
}

/*
PROCEDURE TREE_PRINT_PREORDER(T : Tree)
    IF T = NULL OR T.root = NULL THEN
        OUTPUT "(empty)"
        RETURN
    END IF

    PREORDER_TRAVERSE(T.root)
    OUTPUT end-of-line
END PROCEDURE
*/

/*
PROCEDURE TREE_PRINT_POSTORDER(T : Tree)
    IF T = NULL OR T.root = NULL THEN
        OUTPUT "(empty)"
        RETURN
    END IF

    POSTORDER_TRAVERSE(T.root)
    OUTPUT end-of-line
END PROCEDURE
 */

//  //  BFS (LEVEL-ORDER TRAVERSAL)

typedef struct QueueNode
{
    Node *data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    QueueNode *front;
    QueueNode *rear;
} Queue;

static void InitQueue(Queue *q)
{
    q->front = q->rear = NULL;
}

static int IsEmptyQueue(Queue *q)
{
    return (q->front == NULL);
}

static void Enqueue(Queue *q, Node *node)
{
    QueueNode *qn = (QueueNode *)malloc(sizeof(QueueNode));
    qn->data = node;
    qn->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = qn;
        return;
    }
    q->rear->next = qn;
    q->rear = qn;
}

static Node *Dequeue(Queue *q)
{
    if (IsEmptyQueue(q))
        return NULL;

    QueueNode *temp = q->front;
    Node *node = temp->data;

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return node;
}

/*
PROCEDURE TREE_PRINT_BFS(T : Tree)
    IF T = NULL OR T.root = NULL THEN
        OUTPUT "(empty)"
        RETURN
    END IF

    DECLARE Q : Queue
    INITIALIZE_QUEUE(Q)

    ENQUEUE(Q, T.root)

    WHILE NOT IS_EMPTY(Q) DO
        current ← DEQUEUE(Q)
        OUTPUT current.value

        IF current.left ≠ NULL THEN
            ENQUEUE(Q, current.left)
        END IF

        IF current.right ≠ NULL THEN
            ENQUEUE(Q, current.right)
        END IF
    END WHILE

    OUTPUT end-of-line
END PROCEDURE
 */

// Câu 3 – tìm giá trị lớn nhất trong BST
int TreeMax(const Node *root) {
    if (!root) return -1; // giả sử không gọi với cây rỗng
    if (!root->right) return root->value;
    return TreeMax(root->right);
}
