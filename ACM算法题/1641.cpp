#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int maxm = 1000010;
int fa[maxn];
struct edge{
    int u, v, w;
    edge(){}
    edge(int u, int v, int w):u(u),v(v),w(w){}
}E[maxm];
int find_set(int x){
    if(x==fa[x]) return x;
    else return fa[x] = find_set(fa[x]);
}
void union_set(int x, int y){
    int fx = find_set(x), fy = find_set(y);
    if(fx!=fy){
        fa[fx]=fy;
    }
}
bool cmp(edge a, edge b){
    return a.w<b.w;
}
int n, x, cnt;

int main()
{
    scanf("%d", &n);
    for(int i=0; i<=n; i++) fa[i]=i;
    cnt = 0;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
        	cnt++;
            scanf("%d", &x);
            E[cnt].u=i-1;
            E[cnt].v=j;
            E[cnt].w=x;
        }
    }
    int ans = 0;
    sort(E+1, E+cnt+1, cmp);
    int edgecnt = 0;
    for(int i=1; i<=cnt; i++){
        int x = find_set(E[i].u), y = find_set(E[i].v);
        if(x != y){
            fa[x] = y;
            ans += E[i].w;
            edgecnt++;
            if(edgecnt==n) break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
