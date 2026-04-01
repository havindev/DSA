#include <stdio.h>
#include "stack.h"

void InitStack(Stack *s)
{
    InitQueue(&s->q1);
    InitQueue(&s->q2);
}

// Time: O(n)
int Push(Stack *s, int value)
{
    if (IsEmpty(&s->q2))
    {
        Enqueue(&s->q2, value);
        return 0;
    }
    Enqueue(&s->q1, value);
    while (!IsEmpty(&s->q2))
    {
        int removedValue;
        Dequeue(&s->q2, &removedValue);
        Enqueue(&s->q1, removedValue);
    }
    s->q2 = s->q1;
    while (!IsEmpty(&s->q1))
    {
        int removedValue;
        Dequeue(&s->q1, &removedValue);
    }
    return 0;
}

// Time: O(1)
int Pop(Stack *s)
{
    int removedValue;
    Dequeue(&s->q2, &removedValue);
    return removedValue;
}

// Time: O(1)
int PeekStack(Stack *s)
{
    return s->q2.data[s->q2.front];
}

// Time: O(1)
int Size(Stack *s)
{
    return s->q2.size;
}

// Time: O(1)
int IsEmptyStack(Stack *s)
{
    return s->q2.size == 0;
}

void DisplayStack(Stack *s)
{
    if (IsEmptyStack(s))
    {
        printf("Stack is Empty");
        return;
    }

    printf("Stack (top -> bottom): \n[ ");

    for (int i = s->q2.front; i <= s->q2.rear; i++)
    {
        printf("%d ", s->q2.data[i]);
    }
    printf("]\n");
}
