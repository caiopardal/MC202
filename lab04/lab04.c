#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilha.h"

#define MAXCHAR_NUMBER 500

int main()
{
  int n;
  char number[MAXCHAR_NUMBER];

  p_stack stack = create_stack(); // Create a new stack

  scanf(" %s %d", number, &n);      // Reads number and quantity of digits to remove inside the number
  populate_stack(stack, number);    // Populates the stack with the number
  invert_stack(stack);              // Invert the stack
  delete_digits(stack, n, n, 0, 9); // Delete digits to obtain the smallest number

  destroy_stack(stack); // destroy stack

  return EXIT_SUCCESS;
}
