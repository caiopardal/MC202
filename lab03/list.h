#ifndef LIST_H
#define LIST_H

/* Node of a doubly linked list */
struct Node
{
  int data;
  struct Node *next; // Pointer to next node in DLL
  struct Node *prev; // Pointer to previous node in DLL
};

void push(struct Node **head_ref, int new_data);

void insertAfter(struct Node *prev_node, int new_data);

void append(struct Node **head_ref, int new_data);

void insertBefore(struct Node **head_ref, struct Node *next_node, int new_data);

void printList(struct Node *node);

void deleteNode(struct Node **head_ref, struct Node *del);

void deleteNodeAtGivenPos(struct Node **head_ref, int n);

#endif