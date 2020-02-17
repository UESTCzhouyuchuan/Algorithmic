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
typedef long long ll;
using namespace std;
//freopen("D.in","r",stdin);
//freopen("D.out","w",stdout);
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define maxn 200001
#define mod 10007
#define eps 1e-9
//const int inf=0x7fffffff;   //ÎÞÏÞ´ó
const int inf=0x3f3f3f3f;
/*
inline ll read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
*/
//**************************************************************************************
inline ll read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct edge
{
    int x,y;
};
struct node
{
    int x,y;
};
vector<edge> kiss[maxn];
void add_edge(int a,int b,int c)
{
    kiss[a].push_back((edge){b,c});
    kiss[b].push_back((edge){a,c});
}
int vis[maxn];
int dis[maxn];
int main()
{
    int n;
    n=read();
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        a=read(),b=read(),c=read();
        add_edge(a,b,c);
    }
    queue<int> q;
    q.push(1);
    for(int i=1;i<=n;i++)
        dis[i]=inf;
    dis[1]=0;
    int ans=0;
    int ans1=0;
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    while(!q.empty())
    {
        int now=q.front();
        vis[now]=0;
        q.pop();
        for(int i=0;i<kiss[now].size();i++)
        {
            int next=kiss[now][i].x;
            //cout<<dis[now]+kiss[now][i].y<<" "<<dis[next]<<endl;

            if(dis[now]+kiss[now][i].y<dis[next])
            {
                dis[next]=dis[now]+kiss[now][i].y;
                if(vis[next]==0)
                {
                    vis[next]=1;
                    q.push(next);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dis[i]!=inf&&dis[i]>ans1)
        {
            ans=i;
            ans1=dis[i];
        }
    }
    for(int i=1;i<=n;i++)
        dis[i]=inf;
    dis[ans]=0;
    memset(vis,0,sizeof(vis));
    q.push(ans);
    vis[ans]=1;
    ans=0;
    ans1=0;
    while(!q.empty())
    {
        int now=q.front();
        vis[now]=0;
        q.pop();
        for(int i=0;i<kiss[now].size();i++)
        {
            int next=kiss[now][i].x;
            if(dis[now]+kiss[now][i].y<dis[next])
            {
                dis[next]=dis[now]+kiss[now][i].y;
                if(vis[next]==0)
                {
                    vis[next]=1;
                    q.push(next);
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dis[i]!=inf)
            ans1=max(ans1,dis[i]);
    }
    cout<<ans1<<endl;
}
