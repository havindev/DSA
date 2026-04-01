#include <stdio.h>
#include "stack.h"

int main(int argc, char const *argv[])
{
  TwoStack s;
  init(&s);
  printf("Push 10\n");
  push1(&s, 10);
  printf("Push 20\n");
  push1(&s, 20);
  printf("Push 30\n");
  push1(&s, 30);
  printf("Push 40\n");
  push2(&s, 40);
  printf("Push 50\n");
  push2(&s, 50);

  display(&s);

  printf("Pop from Stack 1: %d\n", pop1(&s));
  printf("Pop from Stack 2: %d\n", pop2(&s));
  display(&s);

    return 0;
}
