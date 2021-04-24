#include <stdlib.h>
#include <stdio.h>

#include "pilha.h"

p_stack create_stack()
{
  p_stack stack;

  stack = malloc(sizeof(Stack));
  if (stack == NULL)
  {
    printf("Not enough memory!\n");
    exit(1);
  }

  // Initialize to NULL and 0
  stack->top = NULL;
  stack->size = 0;

  return stack;
}

void populate_stack(p_stack stack, char number[])
{
  Data data;

  for (int i = 0; number[i] != '\0'; i++)
  {
    // Store the digit and its position
    data.digit = number[i];
    data.pos = i;
    push(stack, data);
  }
}

void invert_stack(p_stack stack)
{
  p_stack aux_stack = create_stack();

  // Dump everything in an auxiliar stack
  while (!is_empty(stack))
    pop_and_push(stack, aux_stack);

  // Make it the new stack, as it inverts when we pop all elements
  stack->top = aux_stack->top;
  stack->size = aux_stack->size;
  free(aux_stack);
}

int is_empty(p_stack stack)
{
  // Check if its null
  return (stack->top == NULL) ? 1 : 0;
}

int get_size(p_stack stack)
{
  return stack->size;
}

Data peek(p_stack stack)
{
  return stack->top->data;
}

void push(p_stack stack, Data data)
{
  p_node node;

  // Allocate a node with the data
  node = malloc(sizeof(Node));
  if (node == NULL)
  {
    printf("Not enough memory!\n");
    exit(1);
  }
  node->data = data;
  node->next = stack->top;

  // Push to the stack
  stack->top = node;
  stack->size++;
}

Data pop(p_stack stack)
{
  // Keep reference to free it later
  p_node top = stack->top;

  // Remove the element
  Data data = top->data;
  stack->top = stack->top->next;
  stack->size--;

  // Free the memory
  free(top);
  return data;
}

void pop_and_push(p_stack src, p_stack dest)
{
  // Push to dest what whas popped from src
  push(dest, pop(src));
}

void pop_and_print(p_stack stack)
{
  Data data = pop(stack);
  printf("%c", data.digit);
}

int char_to_int(char c)
{
  return c - '0';
}

void delete_digits(p_stack stack, int n, int originalQuantityToBeDeleted, int quantityDeleted, int lastSmallest)
{
  int firstDigit = 9;

  if (quantityDeleted == 0)
    firstDigit = char_to_int(peek(stack).digit);

  if (originalQuantityToBeDeleted == 0 || (firstDigit == 0 && quantityDeleted == 0))
  {
    int actualDigit;
    pop_and_print(stack);
    actualDigit = char_to_int(peek(stack).digit);
    if (actualDigit == 0 && firstDigit == 0)
    {
      return;
    }
    else if (actualDigit == 0)
    {
      actualDigit = char_to_int(peek(stack).digit);
      if (actualDigit == 0)
      {
        return;
      }
      else
      {
        while (get_size(stack) != 0)
        {
          pop_and_print(stack);
        }
      }
    }
  }
  else
  {
    // If we want to delete n digits from a n digit number then there is nothing more to print
    if (stack->size <= n)
      return;

    // Keep track of the smallest digit from the n + 1 first digits
    int smallest_digit = 9;
    int target_pos;
    p_stack aux_stack = create_stack();

    // Iterate through the n + 1 first digits to find the smallest digit
    for (int i = 0; i < n + 1; i++)
    {
      pop_and_push(stack, aux_stack);

      if (char_to_int(peek(aux_stack).digit) < smallest_digit)
      {
        smallest_digit = char_to_int(peek(aux_stack).digit);
        target_pos = peek(aux_stack).pos;
        if (smallest_digit == 0)
        {
          break;
        }
      }
    }

    // Put back to the remaining digits everything that goes after the smallest one
    while (peek(aux_stack).pos != target_pos)
      pop_and_push(aux_stack, stack);

    if (((originalQuantityToBeDeleted - quantityDeleted) == 18))
      pop_and_print(aux_stack);
    else
    {
      // Print the smallest one
      if ((lastSmallest != 0 && quantityDeleted > 0) || smallest_digit != 0)
      {
        pop_and_print(aux_stack);
      }
      else
      {
        pop(aux_stack);
      }
    }

    lastSmallest = smallest_digit;

    // Delete the ones that are before the smallest one and store how many were deleted
    int deleted_digits = get_size(aux_stack);
    quantityDeleted += deleted_digits;

    destroy_stack(aux_stack);

    if (deleted_digits == 0 || (originalQuantityToBeDeleted - quantityDeleted) == 0)
    {
      int numOfRemainingDigits = (get_size(stack) - (originalQuantityToBeDeleted - quantityDeleted));

      if ((originalQuantityToBeDeleted - quantityDeleted) > 0)
      {
        delete_digits(stack, (originalQuantityToBeDeleted - quantityDeleted), originalQuantityToBeDeleted, quantityDeleted, lastSmallest);
      }
      else if (numOfRemainingDigits != 0)
      {
        while (get_size(stack) != numOfRemainingDigits)
        {
          pop(stack);
        }

        int lastDigit = 9, actualDigit;
        while (get_size(stack) != 0)
        {
          actualDigit = char_to_int(peek(stack).digit);

          if ((lastDigit == 0 && actualDigit != 0) || (lastDigit != 0 && actualDigit != 0) || (lastDigit != 0 && actualDigit == 0))
          {
            lastDigit = actualDigit;
            pop_and_print(stack);
          }
          else
          {
            pop(stack);
          }
        }

        return;
      }
      else if (numOfRemainingDigits == 0)
      {
        while (get_size(stack) != numOfRemainingDigits)
        {
          pop_and_print(stack);
        }
        return;
      }
    }

    // Repeat the process to the remaining digits and update the number of digits to delete
    delete_digits(stack, n - deleted_digits, originalQuantityToBeDeleted, quantityDeleted, lastSmallest);
  }
}

void destroy_stack(p_stack stack)
{
  destroy_list(stack->top);
  free(stack);
}

void destroy_list(p_node list)
{
  // Recursivelly destroy the list
  if (list != NULL)
  {
    destroy_list(list->next);
    free(list);
  }
}