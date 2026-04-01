#include <stdio.h>

int binary_search(int a[], int n, int target)
{
    /*
        1   start in the middle of the array
        2   look at the middle element
        3   if the middle element is the target
        4       return its position
        5   else if the target is smaller than the middle element
        6       search the left half
        7   else if the target is greater than the middle element
        8       search the right half
        9   repeat until the target is found or no elements remain
        10  if no elements remain
        11      return not found
    */
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (a[mid] == target)
            return mid;
        else if (target < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    int a[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(a) / sizeof(a[0]);
    int target = 9;

    int result = binary_search(a, n, target);

    if (result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not found\n");

    return 0;
}
