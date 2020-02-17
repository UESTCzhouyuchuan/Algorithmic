#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
vector<int> E[maxn];
vector<int> id[maxn];
vector<int>ans1,ans2,ans3;
int vis[maxn];
int V[maxn],d[maxn],fa[maxn],p[maxn];
int n,m,flag=0;
void dfs(int x)
{
    vis[x]=1;
    for(int i=0;i<E[x].size();i++){
        if(vis[E[x][i]])continue;
        d[E[x][i]]++;
        d[x]++;
        ans1.push_back(x);
        ans2.push_back(E[x][i]);
        ans3.push_back(1);
        p[E[x][i]]=ans1.size()-1;
        dfs(E[x][i]);
    }
    if(p[x]==-1){
        if(d[x]%2==0)flag=1;
    }else{
        if(d[x]%2==0){
            d[x]--;
            d[ans1[p[x]]]--;
            ans3[p[x]]=0;
        }
    }
}
int main()
{
    memset(p,-1,sizeof(p));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        E[a].push_back(b);
        E[b].push_back(a);
        id[a].push_back(i);
        id[b].push_back(i);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])dfs(i);
    if(flag){
        cout<<"-1"<<endl;
        return 0;
    }
    int tmp = 0;
    for(int i=0;i<ans1.size();i++)
        if(ans3[i])tmp++;
    cout<<tmp<<endl;
    for(int i=0;i<ans1.size();i++)
        if(ans3[i]==1)
            cout<<ans1[i]<<" "<<ans2[i]<<endl;
    return 0;
}
