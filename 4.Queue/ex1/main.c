#include <stdio.h>
#include "queue.h"

int main()
{
    Queue q;
    InitQueue(&q);

    Enqueue(&q, 10);
    Enqueue(&q, 20);
    Enqueue(&q, 30);
    Enqueue(&q, 40);
    Enqueue(&q, 50);

    printf("Initial Queue:\n");
    DisplayQueue(&q);

    Reverd(&q, 3);
    DisplayQueue(&q);

    return 0;
}
