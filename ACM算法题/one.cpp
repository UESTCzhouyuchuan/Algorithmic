#include <bits/stdc++.h>
using namespace std;
#define INF 0xffffff
using namespace std;
const int maxn = 1010 ;
int n, m, s, t, a, b, d, p;
int G[maxn][maxn];//距离 
int pd[maxn][maxn];//金钱 
int dis[maxn];//距离
int sp[maxn];//花费 
bool vis[maxn];//记录是否走过

void Dij(){
    dis[s] = 0 ;
    sp[s] = 0 ;
    
    for(int k=1; k<=n; k++){
        int Min = INF ;
        int ind = -1 ;
        for(int i=1; i<=n; i++){
            if( !vis[i] && dis[i]<Min){
                ind = i ;
                Min = dis[i];
            }
        }
        vis[ind] = true;
        
        for(int j=1; j<=n; j++){
            if( !vis[j] && dis[ind]+G[ind][j]<dis[j]){
                dis[j] = dis[ind] + G[ind][j];
                sp[j] = sp[ind] + pd[ind][j];
            }
            else if( !vis[j] && dis[j] == dis[ind]+G[ind][j] ){
                sp[j] = min(sp[j],sp[ind]+pd[ind][j]);
            }
        }
    }
}

int main(){
    while( scanf("%d %d",&n, &m) !=EOF ){
        if( n == 0 && m == 0 ) break;
        for(int i=1; i<=n; i++){
            vis[i] = false ;
            sp[i] = INF ;
            dis[i] = INF ;
            for(int j=1; j<=n; j++){
                G[i][j] = INF ;
            }
        }
        while( m -- ){
            scanf("%d %d %d %d",&a, &b, &d, &p);
            G[a][b] = G[b][a] = d ;
            pd[a][b] = pd[b][a] = p ;
        }
        scanf("%d %d", &s, &t);
        Dij();
        cout << dis[t] << " " << sp[t] << endl ;
    }
    return 0;
}
