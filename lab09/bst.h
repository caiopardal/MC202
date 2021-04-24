#ifndef BST_H
#define BST_H

struct node
{
  int value;
  struct node *left, *right;
};

/* Function to create a new node inside BST */
struct node *newNode(int item);

/* Function to insert a node with a defined value in the BST */
struct node *insert(struct node *node, int value);

/* Calculates the height of a BST */
int calculateBSTHeight(struct node *node);

/* Function to delete every node of the BST */
void _deleteTree(struct node *node);

/* Aux function to delete the BST and set it's root to NULL */
void deleteTree(struct node **node_ref);

#endif
