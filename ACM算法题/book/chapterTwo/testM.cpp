#include <bits/stdc++.h>

using namespace std;
int a[100000];
int sum[100000];
int abs(int i, int j)
{
  return (i > j) ? (i - j) : (j - i);
}
int main()
{
  int n;
  scanf("%d", &n);
  memset(a, 0, sizeof(sum));
  for (int i = 0; i < n; i++)
  {
    scanf("%d", a + i);
  }
  for (int j = 0; j < n; j++)
  {
    for (int i = j; i % n != j || i== j; i++)
    {
      sum[j] += abs(a[i%n], i - j +1);
    }
  }
  sort(sum, sum + n);
  printf("%d", sum[0]);
  return 0;
}