#include <stdio.h>

void bubble_sort(int a[], int n)
{

        // 1   start at the beginning of the array

        for (int i = 0; i < n - 1; i++)
        {
            int swapped = 0;
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (a[j] > a[j + 1])
                    {
                        int temp = a[j];
                        a[j] = a[j + 1];
                        a[j + 1] = temp;
                        swapped = 1;
                    }
                }
            if (!swapped)
                {
                    break;
                }

        }
        // 2   compare the first element with the next element
        // 3   if the first element is greater than the next element
        // 4       swap the two elements
        // 5   move to the next pair of elements
        // 6   repeat steps 2–5 until reaching the end of the array
        // 7   go back to the beginning of the array
        // 8   repeat steps 2–7 until no swaps are needed
        // 9   stop

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

    bubble_sort(a, n);
    print_array(a, n);

    return 0;
}
