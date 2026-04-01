#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define MAX 100

typedef struct
{
  int stack[MAX];
  int minStack[MAX];
  int top;
  int minTop;
} MinStack;

void init(MinStack *s);
void push(MinStack *s, int value);
int pop(MinStack *s);
int getMin(const MinStack *s);
void display(const MinStack *s);
void displayMinStack(const MinStack *s);
#endif
