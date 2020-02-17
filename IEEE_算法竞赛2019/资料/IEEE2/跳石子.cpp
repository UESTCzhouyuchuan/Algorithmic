#include<stdio.h>
#include<iostream>
using namespace std;
int l,n,m;
int a[50005];
int L;
int check(int x)
{
    int last = 0;
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]-last<x)
            ans++;
        else
            last = a[i];
    }
    if(ans>m)return 0;
    return 1;
}
int main()
{
    scanf("%d%d%d",&L,&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[n+1]=L;n++;
    int l = 0,r = L;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }
    printf("%d\n",l-1);
}
