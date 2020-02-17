#include<bits/stdc++.h>
using namespace std;

string s[105];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<k;i++)
    {
        string ss;cin>>ss;
        for(int j=0;j<n;j++)
        {
            getline(cin,ss);
            s[j]+=ss;
        }
    }
    string tmp;
    cin>>tmp;
    for(int i=0;i<n;i++)
        cout<<s[i]<<endl;
}
