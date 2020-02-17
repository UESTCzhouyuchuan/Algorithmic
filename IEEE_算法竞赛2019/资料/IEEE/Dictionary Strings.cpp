#include<bits/stdc++.h>
using namespace std;

int a[26];
int b[26];
void init()
{
    memset(a,0,sizeof(a));
}
void solve(){
    int d,p;cin>>d>>p;
    for(int i=0;i<d;i++){
        string s;cin>>s;
        memset(b,0,sizeof(b));
        for(int j=0;j<s.size();j++)
        b[s[j]-'a']++,
        a[s[j]-'a']=max(a[s[j]-'a'],b[s[j]-'a']);
    }
    for(int i=0;i<p;i++)
    {
        string s;cin>>s;
        memset(b,0,sizeof(b));
        int flag=0,ans1=0,ans2=0;
        for(int j=0;j<s.size();j++)
            b[s[j]-'a']++;
        for(int j=0;j<26;j++){
            if(b[j]<a[j])
            {
                flag=-1;
                ans1+=a[j]-b[j];
            }
            if(flag!=-1&&b[j]>a[j])
            {
                flag=1;
                ans2+=b[j]-a[j];
            }
        }
        if(flag==-1)
            cout<<"No"<<" "<<ans1<<endl;
        else if(flag==0)
            cout<<"Yes Yes"<<endl;
        else
            cout<<"Yes No"<<endl;
    }
}
int main()
{
    std::ios_base::sync_with_stdio (false);
    int t;cin>>t;
    while(t--)
    {
        init();
        solve();
    }
    return 0;
}
