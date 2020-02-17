#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7;
int fa[maxn];
pair<int,pair<int,int> >P[maxn];
int fi(int u){
    return u != fa[u] ? fa[u] = fi( fa[u] ) : u;
}
int n,m;
void init()
{
    for(int i=1;i<=n;i++)
        fa[i]=i;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d%d%d",&P[i].second.first,&P[i].second.second,&P[i].first);
    sort(P,P+m);
    int ans = 0,num = 0;
    init();
    for(int i=0;i<m;i++)
    {
        int p1 = P[i].second.first,p2 = P[i].second.second;
        int fa1 = fi(p1),fa2 = fi(p2);
        if(fa1==fa2)continue;
        fa[fa2]=fa1;
        num++,ans=i;
        if(num==n-1)break;
    }
    for(int i=0;i<m;i++)
        if(P[i].first==P[ans].first)
            ans=i;
    long long Ans = 0;
    init();
    for(int i=ans;i>=0;i--)
    {
        int p1 = P[i].second.first,p2 = P[i].second.second;
        int fa1 = fi(p1),fa2 = fi(p2);
        if(fa1==fa2)continue;
        fa[fa2]=fa1;
        Ans=Ans+P[i].first;
    }
    cout<<Ans<<endl;
}
