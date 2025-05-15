#include <stdio.h>
int max(int a, int b)
{
  if (a > b)
  {
    return a;
  }
  else
  {
    return b;
  }
}

int knapsack(int values[], int weights[], int capacity, int n)
{
  int table[n + 1][capacity + 1];

  int i;
  int j;
  for (i = 0; i <= n; i++)
  {
    for (j = 0; j <= capacity; j++)
    {
      if (i == 0 || j == 0)
      {
        table[i][j] = 0;
      }
      else if (weights[i - 1] <= j)
      {
        table[i][j] = max(values[i - 1] + table[i - 1][j - weights[i - 1]], table[i - 1][j]);
      }
      else
      {
        table[i][j] = table[i - 1][j];
      }
    }
  }

  return table[n][capacity];
}

int main(void)
{

  int values[] = {300, 200, 400, 500};
  int weights[] = {2, 1, 5, 3};
  int capacity = 10;
  int n = 4;
  int maxim = knapsack(values, weights, capacity, n);
  printf("Max is : %d", maxim);
  return 0;
}
