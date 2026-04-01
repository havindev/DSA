#include <stdio.h>

#define MAX 100

void insertAt(int arr[], int *size, int item, int index)
{

  if (index < 0 || index > *size)
  {
    printf("Error: Invalid index\n");
    return;
  }

  for (int i = *size - 1; i >= index; i--)
  {
    arr[i + 1] = arr[i];
  }
  arr[index] = item;

  (*size)++;
}

int main(int argc, char const *argv[])
{

  int arr[MAX] = {10, 20, 30, 40};
  int size = 4;

  insertAt(arr, &size, 25, 2);

  printf("After insert: ");
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}

/** Phân tích độ phức tạp:
Time complexity: O(n)
Space complexity: O(1)
*/
