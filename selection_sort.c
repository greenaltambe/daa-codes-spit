#include <stdio.h>

void print_arr(int arr[], int n)
{
  printf("[");
  for (int i = 0; i < n; i++)
  {
    printf("%d", arr[i]);
    if (i < n - 1)
    {
      printf(", ");
    }
  }
  printf("]\n");
}
void selection_sort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int min_idx = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min_idx])
      {
        min_idx = j;
      }
    }
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}
int main()
{
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int n = 10;
  print_arr(arr, n);
  selection_sort(arr, n);
  print_arr(arr, n);
  return 0;
}