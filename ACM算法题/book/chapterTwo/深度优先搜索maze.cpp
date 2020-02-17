//深度优先搜索，用栈stack
#include <bits/stdc++.h>
#define INF 0xffffff
#define MAX_N 100
#define MAX_M 100
#define MAXSIZE 200
using namespace std;

typedef pair<int, int> P1;
typedef pair<P1, int> P;
int N, M;
int sx, sy;
int gx, gy;
char maze[MAX_N][MAX_M + 1];
int d[MAX_N][MAX_M];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool bfs()
{
  P path[MAXSIZE];
  stack<P> stk;
  stk.push(P(P1(sx, sy), -1));
  d[sx][sy] = 0;
  while (stk.size())
  {
    P p = stk.top();
    int i = p.second;
    if (p.first.first == gx && p.first.second == gy)
    {
      printf("一条迷宫的路径如下：");
      int k = 0;
      while (stk.size())
      {
        path[k++] = stk.top();
        stk.pop();
      }
      printf("路径长度为：%d", k);
      while (k > 0)
      {
        k--;
        printf("(%d,%d)-->", path[k].first.first, path[k].first.second);
      }
    }
    bool find = false;
    for (; i < 4; i++)
    {
      int nx = p.first.first + dx[i], ny = p.first.second + dy[i];
      if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF)
      {
        find = true;
        p.second = i;
        stk.pop();
        stk.push(p);
        stk.push(P(P1(nx, ny), -1));
        d[nx][ny] = d[p.first.first][p.first.second] + 1;
        break;
      }
    }
    if (find == false)
    {
      P p = stk.top();
      stk.pop();
      d[p.first.first][p.first.second] = INF;
    }
  }
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
  return 0;
}