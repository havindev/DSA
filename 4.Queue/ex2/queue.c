#include <stdio.h>
#include "queue.h"
#include <malloc.h>

Node *CreateNode(int value)
{
    Node *node = malloc(sizeof(Node));

    node->value = value;
    node->next = NULL;

    return node;
}

Queue *CreateQueue()
{
    Queue *q = malloc(sizeof(Queue));

    q->front = NULL;
    q->rear = NULL;
    q->size = 0;

    return q;
}

// Time: O(1)
int Enqueue(Queue *q, int value)
{
    Node *node = CreateNode(value);
    if (IsEmpty(q))
    {
        q->front = node;
        q->rear = node;
        q->size++;
        return 0;
    }
    q->rear->next = node;
    q->rear = node;
    q->size = q->size + 1;
    return 0;
}

// Time: O(1)
int Dequeue(Queue *q, int *removedValue)
{
    if (IsEmpty(q))
    {
        printf("Queue is Empty");
        return 1;
    }
    if (q->front == q->rear)
    {
        Node *only = q->front;
        if (removedValue != NULL)
        {
            *removedValue = only->value;
        }

        q->front = NULL;
        q->rear = NULL;
        free(only);
        q->size = q->size - 1;
        return 0;
    }
    Node *first = q->front;     // Gán địa chỉ của Node đầu tiên vào Node tạm "first"
    Node *second = first->next; // Gán địa chỉ của Node tiếp theo vào Node tạm "second"
    if (removedValue != NULL)
    {
        *removedValue = first->value;
    }
    first->next = NULL;     // Xóa liên kết giữa Node đầu tiên và Node tiếp theo
    q->front = second;      // Dời con trỏ "front" sang Node tiếp theo
    free(first);            // Xóa Node đầu tiên
    q->size = q->size - 1;  // Giảm Size
    return 0;
}

// Time: O(1)
int Peek(Queue *q, int *frontValue)
{
    if (IsEmpty(q))
    {
        printf("Queue is Empty");
        return 1;
    }
    if (frontValue != NULL)
    {
        *frontValue = q->front->value;
    }
    return 0;
}

// Time: O(1)
int Size(Queue *q)
{
    return q->size;
}

// Time: O(1)
int IsEmpty(Queue *q)
{
    return q->front == NULL;
}

void DisplayQueue(Queue *q)
{
    Node *curr = q->front;

    printf("Front -> Rear\n[ ");
    while (curr != NULL)
    {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL ]\n");
}
