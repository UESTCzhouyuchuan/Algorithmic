#include <bits/stdc++.h>
#define MAX_N 20
using namespace std;

int a[MAX_N];
int n, k;

bool dfs(int i, int sum)
{
  if (i == n)
    return sum == k;
  return dfs(i + 1, sum + a[i]) || dfs(i + 1, sum);
}

int main()
{
  scanf("%d", &n);
  int i = 0;
  while (i < n)
  {
    scanf("%d", a + i);
    i++;
  }
  scanf("%d", &k);
  if (dfs(0, 0))
    printf("YES\n");
  else
  {
    printf("NO\n");
  }
}