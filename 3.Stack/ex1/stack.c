#include "Stack.h"

void init(TwoStack *s)
{
  s->top1 = -1;       // Stack 1 starts from the left
  s->top2 = MAX_SIZE; // Stack 2 starts from the right
}

int isEmpty1(const TwoStack *s)
{
  return (s->top1 == -1);
}

int isEmpty2(const TwoStack *s)
{
  return (s->top2 == MAX_SIZE);
}

int isFull1(const TwoStack *s)
{
  return (s->top1 + 1 == s->top2);
}

int isFull2(const TwoStack *s)
{
  return (s->top2 - 1 == s->top1);
}

void push1(TwoStack *s, int value)
{
  if (isFull1(s))
  {
    printf("Stack 1 overflow\n");
    return;
  }
  s->data[++s->top1] = value;
}

void push2(TwoStack *s, int value)
{
  if (isFull2(s))
  {
    printf("Stack 2 overflow\n");
    return;
  }
  s->data[--s->top2] = value;
}

int pop1(TwoStack *s)
{
  if (isEmpty1(s))
  {
    printf("Stack 1 underflow\n");
    return -1;
  }
  return s->data[(s->top1)--];
}

int pop2(TwoStack *s)
{
  if (isEmpty2(s))
  {
    printf("Stack 2 underflow\n");
    return -1;
  }
  return s->data[(s->top2)++];
}

void display(const TwoStack *s)
{
  printf("Stack 1: ");
  for (int i = s->top1; i >= 0; i--)
  {
    printf("%d ", s->data[i]);
  }
  printf("\n");

  printf("Stack 2: ");
  for (int i = s->top2; i < MAX_SIZE; i++)
  {
    printf("%d ", s->data[i]);
  }
  printf("\n");
}
