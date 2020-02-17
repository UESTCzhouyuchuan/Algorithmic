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
vector<int>V;
map<int,int> H;
int a[maxn];
long long two[maxn];
int main()
{
    scanf("%d",&n);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
        V.push_back(p[i]);
    }
    sort(V.begin(),V.end());
    V.erase(unique(V.begin(),V.end()),V.end());
    for(int i=0;i<V.size();i++)
        H[V[i]]=i;
    for(int i=1;i<=n;i++)
        a[H[p[i]]]++;
    two[0]=1;
    for(int i=1;i<=n;i++)
        two[i]=two[i-1]*2LL%mod;
    for(int i=0;i<V.size();i++)
    {
        for(int j=1;j<=10000;j++)
            dp[gcd(j,V[i])]=add(dp[gcd(j,V[i])],1LL*(two[a[i]]-1)*dp[j]%mod);
        dp[V[i]]=add(dp[V[i]],(two[a[i]]-1));
    }
    int m;scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        printf("%d\n",dp[x]);
    }
}
