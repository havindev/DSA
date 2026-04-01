#include <stdio.h>

void merge(int a[], int l, int m, int r)
{


        // 1   if the array has only one element
        // 2       stop (it is already sorted)
        // 3   split the array into two halves
        // 4   sort the left half
        // 5   sort the right half
        // 6   compare the first elements of both halves
        // 7   take the smaller element and put it into a new array
        // 8   move forward in the half from which the element was taken
        // 9   repeat steps 6–8 until one half is empty
        // 10  copy the remaining elements from the other half
        // 11  the new array is now sorted
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    //Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    int i = 0, j = 0, k = l;
    //merge lại:
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k++] = L[i++];
        }
        else
        {
            a[k++] = R[j++];
        }
    }
//copy phần còn lại của L[] nếu có
    while (i < n1)
    {
        a[k++] = L[i++];
    }


    while (j < n2)
    {
        a[k++] = R[j++];
    }


}

void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;

        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);

        merge(a, l, m, r);
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
    int a[] = {38, 27, 43, 3, 9, 82, 10, 13};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Before sort:\n");
    print_array(a, n);

    merge_sort(a, 0, n - 1);

    printf("After sort:\n");
    print_array(a, n);

    return 0;
}
