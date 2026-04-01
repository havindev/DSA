#include <stdio.h>
#include "hashtable.h"


int main()
{
    int arr[] = {1, 2, 2, 3, 3, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = mostFrequent(arr, n);
    printf("Most Frequent: %d\n", result);

    return 0;
}
