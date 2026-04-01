#include <stdio.h>

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // 1   start at the first element of the array
        // 2   assume this element is the smallest
        int min = i;
        // 3   compare it with the next element
        // 4   if the next element is smaller
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                // 5       update the smallest element
                min = j;
            }
            // 6   move to the next element
            // 7   repeat steps 3–6 until the end of the array
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        // 8   swap the first element with the smallest element found
        // 9   move to the next position in the array
        // 10  repeat steps 2–9 for the remaining unsorted elements
    }
    // 11  stop when all elements are sorted
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[] = {64, 25, 12, 22, 11};
    int n = sizeof(a) / sizeof(a[0]);

    selection_sort(a, n);
    print_array(a, n);

    return 0;
}
