#include <stdlib.h>
#include <stdio.h>

#include "bst.h"

struct node *newNode(int item)
{
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->value = item;
  temp->left = temp->right = NULL;
  return temp;
}

struct node *insert(struct node *node, int value)
{
  if (node == NULL)
    return newNode(value);

  if (value < node->value)
    node->left = insert(node->left, value);
  else if (value > node->value)
    node->right = insert(node->right, value);

  return node;
}

int calculateBSTHeight(struct node *node)
{
  if (node == NULL)
    return 0;
  else
  {
    int lHeight = calculateBSTHeight(node->left);
    int rHeight = calculateBSTHeight(node->right);

    if (lHeight > rHeight)
      return (lHeight + 1);
    else
      return (rHeight + 1);
  }
}

void _deleteTree(struct node *node)
{
  if (node == NULL)
    return;

  _deleteTree(node->left);
  _deleteTree(node->right);

  free(node);
}

void deleteTree(struct node **node_ref)
{
  _deleteTree(*node_ref);
  *node_ref = NULL;
}
