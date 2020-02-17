#include<bits/stdc++.h>
using namespace std;

int dp[50];
struct node{
    int l,r;
    int val;
};
bool cmp(node a,node b)
{
    if(a.r==b.r)return a.l<b.l;
    return a.r<b.r;
}
node p[3005];
void solve()
{
    memset(dp,0,sizeof(dp));
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d",&p[i].l,&p[i].r,&p[i].val);
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++)
        for(int j=p[i].l;j>=0;j--)
            dp[p[i].r]=max(dp[p[i].r],dp[j]+p[i].val);
    int ans = 0;
    for(int i=0;i<50;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}
