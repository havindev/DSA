#include <stdio.h>

int arrayIntersect(int a1[], int size1,
                   int a2[], int size2,
                   int result[])
{

  int resultSize = 0;

  for (int i = 0; i < size1; i++)
  {
    int x = a1[i];

    for (int j = 0; j < size2; j++)
    {

      if (x == a2[j])
      {

        int isDuplicate = 0;

        for (int k = 0; k < resultSize; k++)
        {
          if (result[k] == x)
          {
            isDuplicate = 1;
            break;
          }
        }

        if (!isDuplicate)
        {
          result[resultSize] = x;
          resultSize++;
        }

        break;
      }
    }
  }

  return resultSize;
}

int main(int argc, char const *argv[])
{
  int a1[] = {1, 2, 3, 5};
  int a2[] = {2, 4, 5, 6};

  int size1 = sizeof(a1) / sizeof(a1[0]);
  int size2 = sizeof(a2) / sizeof(a2[0]);

  int result[10];

  int resultSize = arrayIntersect(a1, size1, a2, size2, result);

  printf("Intersection: ");
  for (int i = 0; i < resultSize; i++)
  {
    printf("%d ", result[i]);
  }

  return 0;
}

/** Phân tích độ phức tạp:
Time complexity: O(n × m)
Space complexity: O(min(n, m))
*/
