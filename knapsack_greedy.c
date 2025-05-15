#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int value;
  int weight;
  double ratio;
} Item;

int find_pivot(Item items[], int low, int high)
{
  Item pivot = items[high];
  int i = low - 1;
  for (int j = low; j < high; j++)
  {
    if (items[j].ratio > pivot.ratio)
    {
      i++;
      Item temp = items[i];
      items[i] = items[j];
      items[j] = temp;
    }
  }
  Item temp = items[i + 1];
  items[i + 1] = items[high];
  items[high] = temp;
  return i + 1;
}

void quick_sort(Item items[], int n)
{
  if (n <= 1)
  {
    return;
  }

  int pivot = find_pivot(items, 0, n - 1);
  quick_sort(items, pivot);
  quick_sort(items + pivot + 1, n - pivot - 1);
}

int knapsack(int values[], int weights[], int capacity, int n)
{
  Item items[n];
  for (int i = 0; i < n; i++)
  {
    items[i].value = values[i];
    items[i].weight = weights[i];
    items[i].ratio = (double)values[i] / weights[i];
  }

  quick_sort(items, n);

  int total_value = 0, total_weight = 0;
  for (int i = 0; i < n; i++)
  {
    if (total_weight + items[i].weight <= capacity)
    {
      total_weight += items[i].weight;
      total_value += items[i].value;
    }
  }
  return total_value;
}

int main()
{
  int values[] = {300, 200, 400, 500};
  int weights[] = {2, 1, 5, 3};
  int capacity = 10;
  int n = 4;

  int maxim = knapsack(values, weights, capacity, n);

  printf("Max: %d\n", maxim);

  return 0;
}
