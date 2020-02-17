

#include<bits/stdc++.h>
using namespace std;
int vis[1020];
int ans = 0;
vector<pair<int,int> > p[6];
struct node
{
    int x[6];
    int id;
};
bool cmp1(node a,node b)
{
    return a.x[0]>b.x[0];
}
bool cmp2(node a,node b)
{
    return a.x[1]>b.x[1];
}
bool cmp3(node a,node b)
{
    return a.x[2]>b.x[2];
}
bool cmp4(node a,node b)
{
    return a.x[3]>b.x[3];
}
bool cmp5(node a,node b)
{
    return a.x[4]>b.x[4];
}
bool cmp6(node a,node b)
{
    return a.x[5]>b.x[5];
}
vector<node>v;
void dfs(int x,int A)
{
    if(x==6)
    {
        ans=max(ans,A);
        return;
    }
    for(int i=0;i<p[x].size();i++)
    {
        if(vis[p[x][i].second])
            continue;
        vis[p[x][i].second]=1;
        dfs(x+1,A+p[x][i].first);
        vis[p[x][i].second]=0;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        node tmp;
        for(int j=0;j<6;j++)
            scanf("%d",&tmp.x[j]);
        tmp.id=i;
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),cmp1);
    for(int i=0;i<6;i++)
        p[0].push_back(make_pair(v[i].x[0],v[i].id));
    sort(v.begin(),v.end(),cmp2);
    for(int i=0;i<6;i++)
        p[1].push_back(make_pair(v[i].x[1],v[i].id));
    sort(v.begin(),v.end(),cmp3);
    for(int i=0;i<6;i++)
        p[2].push_back(make_pair(v[i].x[2],v[i].id));
    sort(v.begin(),v.end(),cmp4);
    for(int i=0;i<6;i++)
        p[3].push_back(make_pair(v[i].x[3],v[i].id));
    sort(v.begin(),v.end(),cmp5);
    for(int i=0;i<6;i++)
        p[4].push_back(make_pair(v[i].x[4],v[i].id));
    sort(v.begin(),v.end(),cmp6);
    for(int i=0;i<6;i++)
        p[5].push_back(make_pair(v[i].x[5],v[i].id));
    dfs(0,0);
    cout<<ans<<endl;
}

