#include <stdio.h>

int arrayMax(int arr[], int size)
{

  if (size == 0)
  {
    printf("Error: Array is empty\n");
    return -1;
  }

  int maxValue = arr[0];

  for (int i = 1; i < size; i++)
  {
    if (arr[i] > maxValue)
    {
      maxValue = arr[i];
    }
  }

  return maxValue;
}

int main(int argc, char const *argv[])
{
  int arr[] = {3, 7, 2, 9, 5};
  int size = sizeof(arr) / sizeof(arr[0]);

  int result = arrayMax(arr, size);

  printf("Max value = %d\n", result);

  return 0;
}

/** Phân tích độ phức tạp:
Time complexity: O(n)
Space complexity: O(1)
*/
