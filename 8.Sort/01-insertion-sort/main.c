#include <stdio.h>

void insertionSort(int arr[], int n)
{

    int i , j , key;

    // 1   start at the second element
    for ( i = 1; i < n; i++)
    {
        // 2   pick up the current element as key
        key = arr[i];
        // 3   compare it with the previous element
        j = i - 1;

        // 4   if previous element is greater than key
        while (j >= 0 && arr[j] > key){
        // 5       shift it to the right
            arr[j + 1] = arr[j];
        // 6       move to the previous element
            j--;
        }
        // 7       go back to step 3
        arr[j + 1] = key;
    }



    // 8   else
    // 9       insert key in current position
    // 10  move to the next element
    // 11  repeat from step 2 until done
    // 12  stop

}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
