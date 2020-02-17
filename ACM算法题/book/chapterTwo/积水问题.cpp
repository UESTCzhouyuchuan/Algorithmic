#include <bits/stdc++.h>
#define MAX_N 100
#define MAX_M 100

using namespace std;
char field[MAX_N][MAX_M + 1];
int M, N;
void dfs(int x, int y)
{
  int nx, ny;
  field[x][y] = '.';
  for (int dx = -1; dx <= 1; dx++)
    for (int dy = -1; dy <= 1; dy++)
    {
      nx = x + dx, ny = y + dy;
      if (0 <= nx && nx < N && ny >= 0 && ny < M && field[nx][ny] == 'W')
        dfs(nx, ny);
    }
}
void solve()
{
  int res = 0; //水哇个数
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      if (field[i][j] == 'W')
      {
        dfs(i, j);
        res++;
      }
    }
  }
  printf("%d\n", res);
}

int main(void)
{
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++)
  {
    scanf("%s", field[i]);
    field[i][M] = '\0';
  }
  solve();
  return 0;
}