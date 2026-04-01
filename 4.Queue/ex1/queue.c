#include <stdio.h>
#include "queue.h"

void InitQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int IsEmpty(Queue *q)
{
    return q->size == 0;
}

int IsFull(Queue *q)
{
    return q->size == MAX_SIZE;
}

int Enqueue(Queue *q, int value)
{
    if (IsFull(q))
    {
        printf("Enqueue Failed.");
        return 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    q->size = q->size + 1;

    return 1;
}

int Dequeue(Queue *q, int *removedValue)
{
    if (IsEmpty(q))
    {
        printf("Dequeue Failed");
        return 0;
    }
    *removedValue = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;

    return 1;
}

int Peek(Queue *q, int *frontValue)
{
    if (IsEmpty(q))
    {
        printf("Queue is Empty");
        return 0;
    }

    *frontValue = q->data[q->front];
    return 1;
}

void DisplayQueue(Queue *q)
{
    if (IsEmpty(q))
    {
        printf("Queue is Empty");
        return;
    }

    printf("Queue (front -> rear): [ ");

    for (int i = q->front; i <= q->rear; i++)
    {
        printf("%d ", q->data[i]);
    }
    printf("]\n");
}

int Reverd(Queue *q, int k)
{
    if (q->size == 0)
    {
        printf("Queue is Empty");
        return -1;
    }
    int left = q->front;
    int right = k - 1;
    while (left <= right)
    {
        int temp = q->data[left];
        q->data[left] = q->data[right];
        q->data[right] = temp;
        left++;
        right--;
    }
    return 0;
}