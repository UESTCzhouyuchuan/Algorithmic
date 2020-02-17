#include <bits/stdc++.h>
#define rep(a,b,c) for(int (a)=(b);(a)<=(c);++(a))
#define drep(a,b,c) for(int (a)=(b);(a)>=(c);--(a))
#define pb push_back
#define mp make_pair
#define sf scanf
#define pf printf
#define two(x) (1<<(x))
#define clr(x,y) memset((x),(y),sizeof((x)))
#define dbg(x) cout << #x << "=" << x << endl;
const int mod = 1e9 + 7;
int mul(int x,int y){return 1LL*x*y%mod;}
int qpow(int x , int y){int res=1;while(y){if(y&1) res=mul(res,x) ; y>>=1 ; x=mul(x,x);} return res;}
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;
const int maxn = 1000 + 15;
int a[maxn],b[maxn],ptr[maxn],l[maxn],r[maxn];
vector < int > po[maxn];



int main(int argc,char *argv[]){
    int T=read();
    while(T--){
        int N=read(),M=read();
        rep(i,0,N){
            po[i].clear();
            ptr[i]=0;
        }
        rep(i,1,N){
            a[i]=read();
        }
        rep(i,1,N){
            b[i]=read();
            po[b[i]].pb(i);
        }
        bool ans = true;
        rep(i,1,N){
            if(ptr[a[i]] == po[a[i]].size()) ans = false;
            else a[i]=po[a[i]][ptr[a[i]]++];
        }
        rep(i,1,M) l[i]=read(),r[i]=read();
        if( ans == false ) pf("No\n");
        else{
            rep(i,1,M) sort(a+l[i],a+r[i]+1);
            rep(i,1,N) if(a[i]!=i) ans = false;
            if(ans == true) pf("Yes\n");
            else pf("No\n");
        }
    }
    return 0;
}
