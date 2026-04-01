#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int binary_search(int a[], int n, int target)
{
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
    long long n = 2000000000; // 2_000_000_000
    int *a = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    int target = -1;

    clock_t start = clock();

    int result = binary_search(a, n, target);

    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Result: %d\n", result);
    printf("Time taken: %.10f seconds\n", time_taken);

    free(a);
    return 0;
}