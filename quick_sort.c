#include <stdio.h>

void print_arr(int arr[], int n)
{
  printf("[");
  for (int i = 0; i < n; i++)
  {
    printf("%d", arr[i]);
    if (i != n - 1)
    {
      printf(", ");
    }
  }

  printf("]\n");
}

void swap(int arr[], int a, int b)
{
  int temp = arr[a];
  arr[a] = arr[b];
  arr[b] = temp;
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swap(arr, i, j);
    }
  }

  swap(arr, i + 1, high);
  return i + 1;
}

void quick_sort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot - 1);
    quick_sort(arr, pivot + 1, high);
  }
}

int main(void)
{
  int arr[] = {3, 1, 5, 2, 4};
  int n = 5;
  print_arr(arr, n);
  quick_sort(arr, 0, n - 1);
  print_arr(arr, n);
  return 0;
}
