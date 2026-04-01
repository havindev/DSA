#include <stdio.h>
#include "hashtable.h"

int main(void)
{
    int arr[] = {2,7,11,15};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 9;
    printf("Two Sum indices for target %d: ", target);
    twoSum(arr, n, target);

    return 0;
}