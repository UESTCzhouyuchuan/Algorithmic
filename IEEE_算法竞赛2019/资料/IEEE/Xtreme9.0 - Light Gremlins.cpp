#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

long long ans = 0;
long long p[25];
long long n;
long long two[26];
int num;
void dfs(long long x,long long pp,int flag,int num1)
{
    if(flag)ans+=n/pp*two[num1];
    else ans-=n/pp*two[num1];
    for(int i=x+1;i<num;i++)
    {
        if(1.0*pp*p[i]>1.0*n)continue;
        dfs(i,pp*p[i],1-flag,num1+1);
    }
}
void solve()
{
    two[1]=1;
    for(int i=2;i<26;i++)
        two[i]=two[i-1]*2LL;
    ans=0;
    cin>>n>>num;
    for(int i=0;i<num;i++)
        scanf("%lld",&p[i]);
    for(int i=0;i<num;i++)
        dfs(i,p[i],1,1);
    cout<<ans<<endl;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)solve();
}
