#include <stdio.h>

void arrayReverse(int arr[], int size)
{
  int left = 0;
  int right = size - 1;

  while (left < right)
  {

    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;

    left++;
    right--;
  }
}

int main(int argc, char const *argv[])
{
  int arr[] = {1, 2, 3, 4};
  int size = sizeof(arr) / sizeof(arr[0]);

  arrayReverse(arr, size);

  printf("Reversed array: ");
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
