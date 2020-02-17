#include <bits/stdc++.h>

using namespace std;
int mod=1000000007;
int bfs(int d,int a,int b){
  if (d==1)
    return (a+b)%mod;
  if (d==2)
    return ((a+b)*(a+b)%mod-a*b%mod)%mod;
  long x=(a+b)%mod;
  long y=((a+b)*(a+b)%mod-a*b%mod)%mod;
  long sum=y;
  for (int i=0;i<d-2;i++)
  {
    sum=((a+b)*y%mod-a*b*x%mod)%mod;
    x=y;
    y=sum;
  }
  return sum;
}

int main(){
  int time;
  int n,a,b;
  scanf("%d",&time);
  while(time--){
    scanf("%d %d %d",&n,&a,&b);
    printf("%d\n",bfs(n,a,b));
  }
  return 0;
}