#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long a[3],b;
    cin>>b;
    for(int i=0;i<3;i++)cin>>a[i];
    sort(a,a+3);
    long long ans = 0;
    if(a[0]+a[1]>a[2])ans=(a[0]+a[1]+a[2])/2;
    else ans=a[0]+a[1];
    cout<<min(b,ans)<<endl;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)solve();
}
