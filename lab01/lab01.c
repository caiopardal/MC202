#include <stdio.h>

int main()
{
  int n;    // number of lines and columns
  int i, j; // aux variables

  scanf("%d", &n);

  int matrix[n][n];
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  }

  int pdiag_sum = 0, sdiag_sum = 0, sum_line, sum_column; // variables that represents the sum value
  int evensum_lines = 0, oddsum_columns = 0;              // variables to count number of lines and columns with even or odd sums
  for (i = 0; i < n; i++)
  {
    sum_column = 0;
    sum_line = 0;
    for (j = 0; j < n; j++)
    {
      // calculates the sum of principal diagonal arguments
      if (i == j)
      {
        pdiag_sum = pdiag_sum + matrix[i][j];
      }

      // calculates the sum of secondary diagonal arguments
      if ((i + j) == (n - 1))
      {
        sdiag_sum += matrix[i][j];
      }

      sum_line = sum_line + matrix[j][i];     // calculates the sum of the arguments in a given line
      sum_column = sum_column + matrix[i][j]; //calculates the sum of the arguments in a given column
    }

    // condition to check if the sum of the arguments in a given line is even
    if ((sum_line % 2) == 0)
    {
      evensum_lines = evensum_lines + 1;
    }

    // condition to check if the sum of the arguments in a given column is odd
    if ((sum_column % 2) != 0)
    {
      oddsum_columns = oddsum_columns + 1;
    }
  }

  printf("%d %d %d %d", pdiag_sum, sdiag_sum, evensum_lines, oddsum_columns);

  return 0;
}

// valgrind --leak-check=full ./lab01 < arq01.in