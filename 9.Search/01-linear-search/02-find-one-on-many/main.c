#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linear_search(int *a, int n, int target)
{
    for (int i = 0; i < n; i++)
        if (a[i] == target)
            return i;

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

    int result = linear_search(a, n, target);

    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Result: %d\n", result);
    printf("Time taken: %.6f seconds\n", time_taken);

    free(a);
    return 0;
}