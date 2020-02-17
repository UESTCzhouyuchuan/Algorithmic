#include<bits/stdc++.h>
using namespace std;

const int maxn = 100005;
const int mod = 1e9+7;
int p[maxn],dp[10005],n;
int add(int x,int y){
    x+=y;
    if(x>=mod)x-=mod;
    return x;
}
int gcd(int x,int y)
{
    if(y==0)return x;
    return gcd(y,x%y);
}
int main()
{
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        for(int j=1;j<=10000;j++)
            dp[gcd(j,p[i])]=add(dp[gcd(j,p[i])],dp[j]);
        dp[p[i]]=add(dp[p[i]],1);
    }
    int m;scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",dp[x]);
    }
}
