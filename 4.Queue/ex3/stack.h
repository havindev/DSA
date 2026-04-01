#pragma one
#include "queue.h"

#define MAX_SIZE 100

typedef struct Stack
{
    Queue q1;
    Queue q2;
} Stack;

void InitStack(Stack *s);
int Push(Stack *s, int value);
int Pop(Stack *s);
int PeekStack(Stack *s);
int Size(Stack *s);
int IsEmptyStack(Stack *q);
void DisplayStack(Stack *s);