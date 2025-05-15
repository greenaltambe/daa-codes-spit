#include <stdio.h>

int max(int a, int b)
{
  if (a > b)
  {
    return a;
  }
  return b;
}

int rod_cut(int price[], int n)
{
  int r[n + 1];
  r[0] = 0;

  int q;
  for (int i = 1; i <= n; i++)
  {
    q = -1;
    for (int j = 1; j <= i; j++)
    {
      q = max(q, price[j - 1] + r[i - j]);
    }
    r[i] = q;
  }

  return r[n];
}

int main(void)
{
  int price[] = {1, 5, 8, 9, 10, 17, 20, 24, 30};
  int ans = rod_cut(price, 5);
  printf("Max profit for rod of length 5: %d\n", ans);
  return 0;
}
