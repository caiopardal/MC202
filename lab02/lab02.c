#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 5

void addCoronaVirusPatients(int *arr, int *arrSize, int *capacity, int cases, int ageIndex);
int checkCoronaVirusPatientsBetweenAges(int *arr, int age1, int age2);
void doubleArraySize(int *array, int *capacity, int *size);

int main()
{
  int size = 0, numOfOperations;                                         // array's size | number of operations to be executed
  int capacity = INITIAL_CAPACITY;                                       // array's current capacity
  int *numOfCoronaVirusPatients = calloc(INITIAL_CAPACITY, sizeof(int)); // declaring a new array with 0's inside it's indexes and initial size of 5 integers
  if (numOfCoronaVirusPatients == NULL)
  {
    // allocation failed, exit from the program
    fprintf(stderr, "Out of memory!\n");
    exit(1); // error with calloc, quit the program
  }

  scanf("%d", &numOfOperations); // reads the number of operations to be executed

  int i = 0;
  while (i < numOfOperations)
  {
    int op, x, y;
    scanf("%d %d %d", &op, &x, &y);

    if (op == 0)
    {
      // Check if the position already exists inside the array's capacity, if not increase the capacity's size until it has the index to add
      while ((size > capacity || (capacity - 1) < y))
      {
        int i;

        int u[capacity];

        if (size > 0)
        {
          for (i = 0; i < capacity; i++)
          { // copy the old array values to the temporary one
            u[i] = numOfCoronaVirusPatients[i];
          }
        }

        int *newArr = realloc(numOfCoronaVirusPatients, (capacity * 2) * sizeof(int));

        if (newArr == NULL)
        {
          // allocation failed, exit from the program
          fprintf(stderr, "Out of memory!\n");
          exit(1);
        }

        memset(newArr, 0, (capacity * 2) * sizeof(int)); // initialize all values with 0's

        if (size > 0)
        {
          for (i = 0; i < capacity; i++)
          { // copy all the old array values to the new one
            newArr[i] = u[i];
          }
        }

        capacity = capacity * 2; // increase capacity's size

        numOfCoronaVirusPatients = newArr; // old array points out to the new array
      }

      addCoronaVirusPatients(numOfCoronaVirusPatients, &size, &capacity, x, y);
    }
    else if (op == 1)
    {
      // Check if the position already exists inside the array's capacity, if not increase the capacity's size until it has the index to search
      while ((size > capacity || (capacity - 1) < y))
      {
        int i;

        int u[capacity];

        if (size > 0)
        {
          for (i = 0; i < capacity; i++)
          { // copy the old array values to the temporary one
            u[i] = numOfCoronaVirusPatients[i];
          }
        }

        int *newArr = realloc(numOfCoronaVirusPatients, (capacity * 2) * sizeof(int));

        if (newArr == NULL)
        {
          // allocation failed, exit from the program
          fprintf(stderr, "Out of memory!\n");
          exit(1);
        }

        memset(newArr, 0, (capacity * 2) * sizeof(int)); // initialize all values with 0's

        if (size > 0)
        {
          for (i = 0; i < capacity; i++)
          { // copy all the old array values to the new one
            newArr[i] = u[i];
          }
        }

        capacity = capacity * 2; // increase capacity's size

        numOfCoronaVirusPatients = newArr; // old array points out to the new array
      }

      int numOfCases;
      numOfCases = checkCoronaVirusPatientsBetweenAges(numOfCoronaVirusPatients, x, y);
      printf("%d\n", numOfCases);
    }

    i++;
  }

  free(numOfCoronaVirusPatients); // free the allocated memory

  return 0;
}

void addCoronaVirusPatients(int *arr, int *arrSize, int *capacity, int cases, int ageIndex)
{
  // If there's already an element inside this position, sum the two values
  if (arr[ageIndex] != 0)
  {
    arr[ageIndex] = arr[ageIndex] + cases;
  }
  else
  {
    arr[ageIndex] = cases; // else, just attribute the new value to the index
  }

  *arrSize = *arrSize + 1; //increase array's size

  return;
}

int checkCoronaVirusPatientsBetweenAges(int *arr, int age1, int age2)
{
  int sumOfCases = 0; // aux variable to store the sum of all corona cases

  for (int j = age1; j <= age2; j++)
  { // iterates throught array collecting all cases between age1 and age2
    sumOfCases = sumOfCases + arr[j];
  }

  return sumOfCases;
}
