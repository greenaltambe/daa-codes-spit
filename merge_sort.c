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

void merge(int arr[], int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1];
  int R[n2];

  for (int i = 0; i < n1; i++)
  {
    L[i] = arr[p + i];
  }

  for (int i = 0; i < n2; i++)
  {
    R[i] = arr[q + 1 + i];
  }

  int i = 0;
  int j = 0;
  int k = p;

  while (i < n1 && j < n2)
  {
    if (L[i] < R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }

    k++;
  }

  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int p, int r)
{
  if (p >= r)
  {
    return;
  }

  int q = (p + r) / 2;
  merge_sort(arr, p, q);
  merge_sort(arr, q + 1, r);
  merge(arr, p, q, r);
}

int main(void)
{
  int arr[] = {3, 1, 5, 2, 4};
  int n = 5;
  print_arr(arr, n);
  merge_sort(arr, 0, n - 1);
  print_arr(arr, n);
  return 0;
}
