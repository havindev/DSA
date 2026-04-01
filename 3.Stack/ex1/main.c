#include "stack.h"

int main()
{

  MinStack s;
  init(&s);

  push(&s, 5);
  push(&s, 2);
  push(&s, 10);
  push(&s, 1);

  display(&s);

  printf("Min = %d\n", getMin(&s));

  displayMinStack(&s);

  printf("Pop = %d\n", pop(&s));

  display(&s);
  displayMinStack(&s);

  printf("Min = %d\n", getMin(&s));

  return 0;
}
