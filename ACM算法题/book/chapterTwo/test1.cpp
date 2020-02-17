#include <bits/stdc++.h>
#define M 1000001
using namespace std;
int n, m;
int a[M];
int b[M];
int c[M];
int main()
{
  scanf("%d %d", &n, &m);
  memset(a, 0, sizeof(b));
  for (int i = 2; i < m / 2 + 1; i++)
  {
    for (int j = 2; i * j <= m; j++)
    {
      if (b[i] == 0)
        b[i * j] = 1;
    }
  }
  int t = 0, k = 0;
  bool primer = false;
  printf("ok");
  for (int i = 1; i <= m; i++)
  {
    if (b[i] == 0)
    {
      a[t++] = i;
      if (i == n)
        primer = true;
    }
    else
    {
      c[k++] = i;
    }
  }
  printf("ok\n");
  int count = 0;
  for (int i = 0; i < t; i++)
  {
    for (int j = i; j < t; j++)
    {
      if ((a[i] + a[j] > n))
      {

        if (a[j] - a[i] < n)
        {
          count++;
        }
        else
        {
          break;
        }
    }
  }
  }                      
  printf("ok2");
  if (primer)
  {
    for (int i = 0; i < t; i++)
    {
      for (int j = 0; j < k; j++)
      {
        if ((a[i] + c[j] > n) && (c[j] - a[i] < n) && (a[i] - c[j] < n))
        {
          count++;
        }
      }
    }
  }
  printf("%d", count);
  return 0;
}