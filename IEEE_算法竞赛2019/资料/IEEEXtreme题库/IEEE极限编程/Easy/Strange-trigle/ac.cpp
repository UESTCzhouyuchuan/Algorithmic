#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int n;
void solve()
{
    scanf("%d",&n);
    for(int i=1;;i++)
    {
        if(n<=i)
        {
            printf("%d\n",n*2-1);
            break;
        }
        n-=i;
    }
}
int main()
{
    freopen("000.in","r",stdin);
    freopen("000.out","w",stdout);
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}
