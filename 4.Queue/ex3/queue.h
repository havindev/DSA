#pragma one

#define MAX_SIZE 100

typedef struct Queue
{
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

void InitQueue(Queue *q);
int IsEmpty(Queue *q);
int IsFull(Queue *q);
int Enqueue(Queue *q, int value);
int Dequeue(Queue *q, int *removedValue);
int Peek(Queue *q, int *frontValue);
void DisplayQueue(Queue *q);
int Reverd(Queue *q, int k);