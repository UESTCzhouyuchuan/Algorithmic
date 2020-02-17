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
#include <stack>
typedef long long ll;
using namespace std;
//freopen("D.in","r",stdin);
//freopen("D.out","w",stdout);
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define test freopen("test.txt","r",stdin)
#define maxn 200001
#define mod 10007
#define eps 1e-9
int Num;
char CH[20];
//const int inf=0x7fffffff;   //§ß§é§à§é¨f§³
const int inf=0x3f3f3f3f;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void P(int x)
{
    Num=0;if(!x){putchar('0');puts("");return;}
    while(x>0)CH[++Num]=x%10,x/=10;
    while(Num)putchar(CH[Num--]+48);
    puts("");
}
//**************************************************************************************

string s;
int n;
const int p[18]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
int a[30];
int main()
{
    while(cin>>s>>n)
    {
        memset(a,0,sizeof(a));
        ll tmp=0;
        ll k=1;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]<='9'&&s[i]>='0')
                tmp+=(s[i]-'0')*k;
            else if(s[i]<='Z'&&s[i]>='A')
                tmp+=(s[i]-'A'+10)*k;
            else
                tmp+=(s[i]-'a'+36)*k;
            k*=n;
        }
        for(int i=0;i<18;i++)
        {
            while(n%p[i]==0&&n>0)
            {
                n/=p[i];
                a[i]++;
            }
        }
        ll ans=(1LL<<63)-1;
        for(int i=0;i<18;i++)
        {
            ll now=tmp,tot=0;
            while(now>0)
            {
                now/=p[i];
                tot+=now;
            }
            if(a[i]>0)
                ans=min(ans,tot/a[i]);
        }
        printf("%lld\n",ans);
    }

}
