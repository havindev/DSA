#include <stdio.h>
#include "stack.h"

int main()
{
    Stack s;
    InitStack(&s);

    printf("%s\n", IsEmptyStack(&s) ? "Is Empty" : "Not Empty");

    Push(&s, 5);
    Push(&s, 3);
    Push(&s, 4);
    Push(&s, 1);
    Push(&s, 2);
    Push(&s, 7);

    DisplayStack(&s);

    printf("Pop: %d\n", Pop(&s));

    DisplayStack(&s);

    printf("Peek: %d\n", PeekStack(&s));
    
    printf("Size: %d\n", Size(&s));

    printf("%s\n", IsEmptyStack(&s) ? "Is Empty" : "Not Empty");

    return 0;
}
