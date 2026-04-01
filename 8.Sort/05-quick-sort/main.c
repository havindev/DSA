#include <stdio.h>

#include <stdio.h>

// partition
int partition(int a[], int low, int high)
{
    /*
        1   if the array has zero or one element
        2       stop (it is already sorted)
        3   pick a pivot element from the array
        4   compare each element with the pivot
        5   if element is smaller than pivot
        6       move it to the left side
        7   else if element is greater than pivot
        8       move it to the right side
        9   place the pivot between the two sides
        10  sort the left side
        11  sort the right side
        12  stop
    */
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return i + 1;
}

// quick sort
void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);

        quick_sort(a, low, pi - 1);
        quick_sort(a, pi + 1, high);
    }
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sort:\n");
    print_array(a, n);

    quick_sort(a, 0, n - 1);

    printf("After sort:\n");
    print_array(a, n);

    return 0;
}
