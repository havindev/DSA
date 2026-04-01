#include <stdio.h>
#include "hashtable.h"

int main(void)
{
    int arr[] = {1,7,5,9,2,12,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    printf("Count pairs with diff %d = %d\n", k, countPairsWithDiff(arr, n, k));

    return 0;
}
