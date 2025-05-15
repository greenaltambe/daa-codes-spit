#include <stdio.h>

void bubble_sort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
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
int main()
{
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int n = 10;
  print_arr(arr, n);
  bubble_sort(arr, n);
  print_arr(arr, n);
  return 0;
}