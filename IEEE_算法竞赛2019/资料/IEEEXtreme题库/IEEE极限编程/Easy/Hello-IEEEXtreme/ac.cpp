#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int c[30];
int main()
{
    freopen("000.in","r",stdin);
    freopen("000.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        cin>>s;
        memset(c,0,sizeof(c));
        for(int i=0;i<s.size();i++)
            c[s[i]-'a']++;
        int ans = 1e9;
        ans=min(ans,c['h'-'a']);
        ans=min(ans,c['l'-'a']/2);
        ans=min(ans,c['o'-'a']);
        ans=min(ans,c['i'-'a']);
        ans=min(ans,c['i'-'a']);
        ans=min(ans,c['e'-'a']/6);
        ans=min(ans,c['x'-'a']);
        ans=min(ans,c['t'-'a']);
        ans=min(ans,c['r'-'a']);
        ans=min(ans,c['m'-'a']);
        printf("%d\n",ans);
    }
}
