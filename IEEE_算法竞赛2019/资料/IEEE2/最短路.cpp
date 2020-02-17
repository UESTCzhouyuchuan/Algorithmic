//qscqesze
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
#include <stack>
typedef long long ll;
using namespace std;
//freopen("D.in","r",stdin);
//freopen("D.out","w",stdout);
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define test freopen("test.txt","r",stdin)
#define maxn 200000
#define mod 10007
#define eps 1e-9
int Num;
char CH[20];
const int inf=0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3fLL;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void P(int x)
{
    Num=0;if(!x){putchar('0');puts("");return;}
    while(x>0)CH[++Num]=x%10,x/=10;
    while(Num)putchar(CH[Num--]+48);
    puts("");
}
//**************************************************************************************

int dp[110][110];
int main()
{
    //test;
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            break;
        memset(dp,inf,sizeof(dp));
        for(int i=1;i<=n;i++)
            dp[i][i]=0;
        for(int i=0;i<m;i++)
        {
            int x=read(),y=read(),c=read();
            dp[x][y]=dp[y][x]=c;
        }
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        cout<<dp[1][n]<<endl;
    }
}
