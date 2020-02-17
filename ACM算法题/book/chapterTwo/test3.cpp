#include <bits/stdc++.h>

using namespace std;
int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool bfs(int year)
{
  return year % 400 == 0 || (year % 4 == 0 && year % 100);
}

int main(void)
{
  int year, m, d, a, b;
  int t;
  int sum;
  scanf("%d", &t);
  while (t--)
  {
    scanf("%d %d %d %d %d", &year, &m, &d, &a, &b);
    if (bfs(year))
    {
      month[2] = 29;
    }
    else
    {
      month[2] = 28;
    }
    sum = 0;
    if (a > m)
    {
      sum += month[m] - d;
      for (int i = m + 1; i < a; i++)
      {
        sum += month[i];
      }
      sum += b;
    }
    else if (a == m && b >= d)
    {
      sum = b - d;
    }
    else
    {
      sum += month[m] - d;
      for (int i = m + 1; i <= 12; i++)
      {
        sum += month[i];
      }
      if (bfs(year + 1))
      {
        month[2] = 29;
      }
      else
      {
        month[2] = 28;
      }
      for (int i = 1; i < a; i++)
        sum += month[i];
      sum += b;
    }
    printf("%d\n", sum);
  }
}