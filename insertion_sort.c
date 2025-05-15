#include <stdio.h>

void insertion_sort(int arr[], int n)
{
  for (int i = 1; i < n; i++)
  {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
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
int main(void)
{
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int n = 10;
  print_arr(arr, n);
  insertion_sort(arr, n);
  print_arr(arr, n);
  return 0;
}