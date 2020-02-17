#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int g[maxn][maxn],n,m,k;
void solve()
{
    memset(g,0,sizeof(g));
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x][y]=1;
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(g[i][k]==1&&g[k][j]==1)g[i][j]=1;

    for(int i=1;i<=k;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(g[x][y]&&g[y][x])cout<<"="<<endl;
        else if(g[x][y])cout<<">="<<endl;
        else if(g[y][x])cout<<"<="<<endl;
        else cout<<"?"<<endl;
    }
}
int main()
{
    freopen("000.in","r",stdin);
    freopen("000.out","w",stdout);
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}
