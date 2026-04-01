#pragma one

typedef struct Node 
{
    int value;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue *CreateQueue();
int Enqueue(Queue *q, int value);
int Dequeue(Queue *q, int *removedValue);
int Peek(Queue *q, int *frontValue);
int Size(Queue *q);
int IsEmpty(Queue *q);
void DisplayQueue(Queue *q);