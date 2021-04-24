#include <stdio.h>
#include <stdlib.h>

// Function to merge two sorted arrays
long long int mergeSortedArrays(int *arr, int *aux, int first, int mid, int last)
{
  int k = first, i = first, j = mid + 1;
  long long int inversionCount = 0;

  // While there are elements in the left and right
  while (i <= mid && j <= last)
  {
    if (arr[i] <= arr[j])
    {
      aux[k++] = arr[i++];
    }
    else
    {
      aux[k++] = arr[j++];
      inversionCount += (mid - i + 1);
    }
  }

  // Copy all the remaining elements
  while (i <= mid)
    aux[k++] = arr[i++];

  // copy back to the original array
  for (int i = first; i <= last; i++)
    arr[i] = aux[i];

  return inversionCount;
}

// Implementation of merge sort to sort arrays
long long int mergeSort(int *arr, int *aux, int first, int last)
{
  // Base case of the recursion
  if (last == first) // if size == 1, just return
    return 0;

  // find the mid element inside the array
  int mid = (first + ((last - first) >> 1));
  long long int inversionCount = 0;

  // split and merge left side of the array
  inversionCount += mergeSort(arr, aux, first, mid);

  // split and merge right side of the array
  inversionCount += mergeSort(arr, aux, mid + 1, last);

  // merge the two separated parts of the original array
  inversionCount += mergeSortedArrays(arr, aux, first, mid, last);

  return inversionCount;
}

int main()
{
  int n;
  scanf("%d", &n); // Reads the num of elements inside the array

  int *arr = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  int *aux = malloc(n * sizeof(int));
  for (int i = 0; i < n; i++)
    aux[i] = arr[i];

  // Calls merge sort function to return the number of inversions
  printf("%lli\n", mergeSort(arr, aux, 0, n - 1));

  free(arr);
  free(aux);

  return 0;
}