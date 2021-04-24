#include <stdio.h>

#include "list.h"

int main()
{
  int numOfClients, firstClient, firstCriteria, secCriteria;

  scanf("%d %d %d %d", numOfClients, firstClient, firstCriteria, secCriteria);

  struct Node *head = NULL;

  append(&head, firstClient);                                       // Insert the first client to the head of the list
  insertAfter(head->next, ((firstClient + 1) % numOfClients));      // Insert the second client
  append(&head, ((firstClient - 1 + numOfClients) % numOfClients)); // Insert the last client to the end of the list

  printf("Created DLL is: ");
  printList(head);

  getchar();
  return 0;
}