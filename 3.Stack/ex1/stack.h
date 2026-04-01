#ifndef STACK_H
#define STACK_H

#include <stdio.h>

#define MAX_SIZE 100

typedef struct
{
  int data[MAX_SIZE];
  int top1;
  int top2;
} TwoStack;

void init(TwoStack *s);

void push1(TwoStack *s, int value);
void push2(TwoStack *s, int value);

int pop1(TwoStack *s);
int pop2(TwoStack *s);

int isEmpty1(const TwoStack *s);
int isEmpty2(const TwoStack *s);

int isFull1(const TwoStack *s);
int isFull2(const TwoStack *s);

void display(const TwoStack *s);
#endif
