#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5+7;
const int mod = 1e9+7;
int a[maxn];
int main()
{
    int n,m;scanf("%d",&n);
    long long ans = 0,sum = 0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i],sum%=mod;
    }
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int x;
        scanf("%d",&x);
        sum=(sum+sum)%mod;

    }
    cout<<sum<<endl;
}
