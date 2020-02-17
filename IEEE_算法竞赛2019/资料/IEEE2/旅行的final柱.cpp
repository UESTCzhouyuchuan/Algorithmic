#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
string s;
vector<int>E[maxn];
int vis[maxn];
void dfs(int x,int flag)
{
    vis[x]=1;
    if(flag==0)printf("%d ",x);
    for(int i=0;i<E[x].size();i++)
    {
        if(vis[E[x][i]])continue;
        dfs(E[x][i],!flag);
    }
    if(flag==1)printf("%d ",x);
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=0;j<s.size();j++)
            if(s[j]=='1')E[i].push_back(j+1);
    }
    dfs(1,0);
}

