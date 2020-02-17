//宽度优先搜索，队列，
#include <bits/stdc++.h>
#define INF 0xffffff
#define MAX_N 100
#define MAX_M 100
using namespace std;

typedef pair<int, int> P;
int N, M;
int sx, sy;
int gx, gy;
char maze[MAX_N][MAX_M + 1];
int d[MAX_N][MAX_M];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int bfs()
{
  queue<P> que;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      d[i][j] = INF;
  que.push(P(sx, sy));
  d[sx][sy] = 0;
  while (que.size())
  {
    P p = que.front();
    que.pop();
    if (p.first == gx && p.second == gy)
      break; //找到终点，退出循环
    for (int i = 0; i < 4; i++)
    {
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF)
      {
        que.push(P(nx, ny));
        d[nx][ny] = d[p.first][p.second] + 1;
      }
    }
  }
  return d[gx][gy];
}
int main(void)
{
  char ch;
  scanf("%d %d", &N, &M);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      ch = getchar();
      maze[i][j] = ch;
      if (ch == 'S')
      {
        sx = i;
        sy = j;
      }
      if (ch == 'G')
      {
        gx = i;
        gy = j;
      }
    }
    getchar();
    maze[i][M] = '\0';
  }
  printf("%d", bfs());
  return 0;
}