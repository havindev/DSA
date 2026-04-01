#include "stack.h"

void init(MinStack *s)
{
  s->top = -1;
  s->minTop = -1;
}

void push(MinStack *s, int value)
{
  if (s->top == MAX - 1)
  {
    printf("Stack overflow\n");
    return;
  }
  s->stack[++s->top] = value;

  // Cập nhật minStack
  if (s->minTop == -1 || value <= s->minStack[s->minTop])
  {
    s->minStack[++s->minTop] = value;
  }
}

int pop(MinStack *s)
{
  if (s->top == -1)
  {
    printf("Stack underflow\n");
    return -1;
  }
  int popValue = s->stack[s->top--];

  if (popValue == s->minStack[s->minTop])
  {
    s->minTop--;
  }
  return popValue;
}

int getMin(const MinStack *s)
{
  if (s->minTop == -1)
  {
    printf("Stack is empty\n");
    return -1;
  }
  return s->minStack[s->minTop];
}

void display(const MinStack *s)
{
  if (s->top == -1)
  {
    printf("Stack is empty\n");
    return;
  }
  printf("Stack: ");
  for (int i = s->top; i >= 0; i--)
  {
    printf("%d ", s->stack[i]);
  }
  printf("\n");
}
void displayMinStack(const MinStack *s)
{
  if (s->minTop == -1)
  {
    printf("Min Stack is empty\n");
    return;
  }
  printf("Min Stack: ");
  for (int i = s->minTop; i >= 0; i--)
  {
    printf("%d ", s->minStack[i]);
  }
  printf("\n");
}
