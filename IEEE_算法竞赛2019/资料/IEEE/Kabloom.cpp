#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+6;


int add(char a,char b){
    if(a=='R'&&b=='R')return 50;
    if(a=='R'){
        if(b=='A')return 20;
        if(b=='Q')return 15;
        if(b=='K')return 15;
        if(b=='J')return 15;
        if(b=='T')return 10;
        return b-'0';
    }
    if(b=='R'){
        if(a=='A')return 20;
        if(a=='Q')return 15;
        if(a=='K')return 15;
        if(a=='J')return 15;
        if(a=='T')return 10;
        return a-'0';
    }
    if(a=='A')return 20;
    if(a=='Q')return 15;
    if(a=='K')return 15;
    if(a=='J')return 15;
    if(a=='T')return 10;
    return a-'0';
}
char a[maxn][5],b[maxn][5];
int n,dp[maxn][maxn];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            scanf("%s",a[i]);
        for(int i=1;i<=n;i++)
            scanf("%s",b[i]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(a[i][0]==b[j][0]||a[i][0]=='R'||b[j][0]=='R'){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-1]+add(a[i][0],b[j][0]));
                }
            }
        }
        cout<<dp[n][n]*2<<endl;
    }
}
