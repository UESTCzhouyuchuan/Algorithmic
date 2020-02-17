#include<bits/stdc++.h>
using namespace std;
const int maxn = 1050;
const double eps = 1e-7;
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
double dp[2][maxn],ans;
double p[maxn];
int n,m,x,y,now;
int main()
{
    while(cin>>n)
    {
        if(n==0)break;
        ans=0;
        memset(dp,0,sizeof(dp));
        dp[0][1]=1.0;
        for(int i=1;i<n;i++)cin>>p[i];
        double now = 1;
        double ans = 1;
        for(int i=n-1;i>=1;i--)
        {
            now/=p[i];
            ans+=now;
        }
        printf("%.0f\n",ans);
    }
}
