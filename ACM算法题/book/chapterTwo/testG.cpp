#include <bits/stdc++.h>

using namespace std;

int Result[32];
int r_len=0;
void print(int a[],int a_len){
  for (int i =a_len-1;i>=0;i--)
    printf("%d",a[i]);
  printf("\n");
}
int sub(int a[], int b[], int a_len, int b_len)
{
  int i;
  if (a_len < b_len)
  {
    return -1;
  }
  else if (a_len == b_len)
  {
    for (i = a_len-1; i >= 0; i--)
    {
      if (a[i] > b[i])
        break;
      else if (a[i] < b[i])
        return -1;
    }
  }
  for (i = 0; i < a_len; i++)
  {//要求i>b_len时b[i]为0
    a[i] -= b[i];
    if (a[i] < 0)
    {
      a[i] += 10;
      a[i + 1]--;
    }
  }
  for (i = a_len -1; i >= 0; i--)
  {
    if (a[i] != 0)
      return i + 1;
  }
  return 0;
}
void add(int a[], int a_len)
{
  int i = 0;
  for (i = 0; i < a_len; i++)
  {
    Result[i] += a[i];
    if (Result[i] >= 10)
    {
      Result[i] = Result[i] % 10;
      Result[i+1]++;
    }
  }
  int len = (a_len > r_len) ? a_len : r_len;
  for (; i < len; i++)
  {
    if (Result[i] >= 10)
    {
      Result[i] = Result[i] % 10;
      Result[i+1]++;
    }
  }
  if (Result[i] > 0)
  {
    len++;
  }
  r_len = len;
}
void dfs(int a[], int b[], int a_len, int b_len)
{
  if (b_len == 0)
    return;
  int t, len = a_len - b_len;
  int result[16],res_len;
  memset(result,0,sizeof(result));
  int i;
  if (len)
  {
    for (i = b_len - 1; i >= 0; i--)
    {
      b[i + len] = b[i];
    }
    memset(b, 0, len * sizeof(int));
  }
  for (i = 0; i <= len; i++)
  {
    while ((t = sub(a, b + i, a_len, b_len + len - i)) >= 0)
    {
      a_len = t;
      result[len - i]++;
    }
  }
  res_len = len;
  if (result[len] == 0)
    res_len--;
  add(result, res_len + 1);
  if (len)
  {
    for (i = 0; i < b_len; i++)
      a[i] = a[i + len];
    memset(b+b_len,0,len*sizeof(int));
  }
  dfs(b, a, b_len, a_len);
}
int main(void)
{
  int P[32], R[32];
  int P_len, R_len;
  char ch[17];
  int i = 0, k = 0;
  memset(P,0,sizeof(P));
  memset(R,0,sizeof(R));
  memset(Result,0,sizeof(Result));
  scanf("%s",ch);
  P_len = strlen(ch);
  for (i = P_len - 1; i >= 0; i--)
  {
    P[k++] = ch[i] - '0';
  }
  scanf("%s",ch);
  R_len = strlen(ch);
  k = 0;
  for (i = R_len - 1; i >= 0; i--)
  {
    R[k++] = ch[i] - '0';
  }
  dfs(P, R, P_len, R_len);
  print(Result,r_len);
  return 0;
}