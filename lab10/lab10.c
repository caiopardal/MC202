#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

int main()
{
  int n, numOfCollisions = 0;
  scanf("%d", &n); // Reads the hash table size and num of elements that will be inserted in the hash table

  int *arrHash = malloc(n * sizeof(int)); // array that will store DN's tree numbers
  for (int i = 0; i < n; i++)
    scanf("%d", &arrHash[i]); // Reads and store every element that will be used in the hash table

  struct hashTableItem *array = malloc(n * sizeof(struct hashTableItem)); // Instantiates a new hash table array

  initHashTable(array, n); // Initialize hash table

  for (int j = 0; j < n; j++)
  {
    int aux = insertAndReturnNumOfCollisions(array, arrHash[j], arrHash[j], n);
    numOfCollisions = numOfCollisions + aux;
  }

  printf("%d\n", numOfCollisions); // print the number of collisions that happened

  free(arrHash);
  free(array);

  return 0;
}