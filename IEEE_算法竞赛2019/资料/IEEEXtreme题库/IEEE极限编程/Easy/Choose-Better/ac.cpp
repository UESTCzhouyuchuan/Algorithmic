#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
pair<long long,long long> a[3][maxn];
int t,n;
void solve()
{
    scanf("%d",&n);
    for(int i=0;i<3;i++)for(int j=1;j<=n;j++)scanf("%lld",&a[i][j].first),a[i][j].second=j;
    for(int i=0;i<3;i++)sort(a[i]+1,a[i]+1+n);
    for(int i=0;i<3;i++)reverse(a[i]+1,a[i]+1+n);
    long long ans = 0;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=0;k<3;k++)
            {
                if(a[0][i].second==a[1][j].second)continue;
                if(a[0][i].second==a[2][k].second)continue;
                if(a[1][j].second==a[2][k].second)continue;
                ans=max(ans,a[0][i].first+a[1][j].first+a[2][k].first);
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("000.in","r",stdin);
    freopen("000.out","w",stdout);
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
