#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main()
{
  int n;
  scanf("%d", &n); // Reads the num of elements that will result in a tree

  int heightOfDNsTree = 0, heightOfMentsTree = 0; // Heights of the trees

  int *arrDN = malloc(n * sizeof(int)); // array that will store DN's tree numbers
  for (int i = 0; i < n; i++)
    scanf("%d", &arrDN[i]); // Reads and store every node of the tree

  struct node *rootOfDNsTree = NULL;               // Creates a new root for the BST
  rootOfDNsTree = insert(rootOfDNsTree, arrDN[0]); // Insert a value to the tree node

  for (int j = 1; j < n; j++)
    insert(rootOfDNsTree, arrDN[j]); // creates the tree

  heightOfDNsTree = calculateBSTHeight(rootOfDNsTree); // calculates the height of the tree

  int *arrMent = malloc(n * sizeof(int)); // array that will store Ment's tree numbers
  for (int i = 0; i < n; i++)
    scanf("%d", &arrMent[i]); // Reads and store every node of the tree

  // repeat the same proccess to Ment's tree
  struct node *rootOfMentsTree = NULL;
  rootOfMentsTree = insert(rootOfMentsTree, arrMent[0]);

  for (int z = 1; z < n; z++)
    insert(rootOfMentsTree, arrMent[z]);

  heightOfMentsTree = calculateBSTHeight(rootOfMentsTree);

  printf("%d %d\n", heightOfDNsTree, heightOfMentsTree); // print the values of each tree height

  // free all the memory that we used
  deleteTree(&rootOfDNsTree);
  deleteTree(&rootOfMentsTree);

  free(arrDN);
  free(arrMent);

  return 0;
}
