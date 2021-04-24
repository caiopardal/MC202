#ifndef HASH_H
#define HASH_H

struct hashData
{
  int key;
  int value;
};

struct hashTableItem
{
  int auxFlag;
  /*
    * auxFlag = 0 : data does not exist
    * auxFlag = 1 : data exists
    * auxFlag = 2 : data existed at least once
  */
  struct hashData *data;
};

/* Function to initialize a new hash table */
void initHashTable(struct hashTableItem *arr, int capacity);

/* Function to generate a new hashcode to insert the element at this position */
int hashcode(int key, int capacity);

/* to insert an element in the hash table and return the num of collisions that happened */
int insertAndReturnNumOfCollisions(struct hashTableItem *arr, int key, int value, int capacity);

#endif
