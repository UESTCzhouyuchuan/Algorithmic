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
#define maxn 100001
#define eps 1e-9
const int inf=9999999;   //ÎÞÏÞ´ó
//**************************************************************************************
int MOD=100003;
ll powmod(ll a,ll b) {
    ll ans = 1,x = a;
    while (b) {
        if (b & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        b >>= 1;
    }
    return ans;
}
int main()
{
    ll m;
    ll n;
    cin>>m>>n;
    ll kiss=powmod(m,n);
    cout<<(kiss+MOD-(m*powmod(m-1,n-1))%MOD)%MOD<<endl;
}
