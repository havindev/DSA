#include <stdio.h>
#include "queue.h"

int main()
{
    Queue *q = CreateQueue();

    Enqueue(q, 10);
    Enqueue(q, 20);
    Enqueue(q, 30);
    Enqueue(q, 40);
    Enqueue(q, 50);

    DisplayQueue(q);

    int removedValue;
    Dequeue(q, &removedValue);
    printf("\nDequeue Value: %d\n", removedValue);

    DisplayQueue(q);

    int frontValue;
    Peek(q, &frontValue);
    printf("\nPeek Value: %d\n", frontValue);

    DisplayQueue(q);

    int size = Size(q);
    printf("\nSize: %d\n", size);
    return 0;
}
