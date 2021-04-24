#include <stdio.h>
#include <stdlib.h>

// Shell sort implementation
void shellSort(int *array, int n)
{
  for (int interval = n / 2; interval > 0; interval /= 2)
  { // Reorder elements at n/2, n/4, n/8, ...
    for (int i = interval; i < n; i += 1)
    {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
      {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}

int main()
{
  int n, k;
  scanf("%d %d", &n, &k); // Reads the num of elements inside the array and the chosen element to be printed

  int *arr = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  // Calls shell sort function to return the ordered array
  shellSort(arr, n);

  printf("%d\n", arr[k - 1]);

  free(arr);

  return 0;
}