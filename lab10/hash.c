#include <stdlib.h>
#include <stdio.h>

#include "hash.h"

void initHashTable(struct hashTableItem *arr, int capacity)
{
  int i;
  for (i = 0; i < capacity; i++)
  {
    arr[i].auxFlag = 0;
    arr[i].data = NULL;
  }
}

/* Function to generate a new hashcode to insert the element at this position */
int hashcode(int key, int capacity)
{
  return (key % capacity);
}

/* to insert an element in the hash table and return the num of collisions that happened */
int insertAndReturnNumOfCollisions(struct hashTableItem *arr, int key, int value, int capacity)
{
  int index = hashcode(key, capacity);
  int i = index, numOfCollisions = 0;

  /* First, we create a new data to be inserted */
  struct hashData *newData = (struct hashData *)malloc(sizeof(struct hashData));
  newData->key = key;
  newData->value = value;

  /* loop through the array to find an empty space to insert the item */
  while (arr[i].auxFlag == 1)
  {
    numOfCollisions++;

    i = (i + 1) % capacity; // Linear probing to get a new hashcode

    if (i == index)
    {
      return numOfCollisions; // hash table is full, so we return because we can't insert any more item
    }
  }

  arr[i].auxFlag = 1;
  arr[i].data = newData;

  free(newData);

  return numOfCollisions;
}
