#include<bits/stdc++.h>
using namespace std;
int last;
string s;
string get(string ss)
{
    string tmp;
    int p=ss.size();
    while(p)
    {
        tmp+=p%10+'0';
        p/=10;
    }
    reverse(tmp.begin(),tmp.end());
    return tmp;
}
int main()
{
    while(cin>>s)
    {
        if(s[0]=='E')break;//读到EOF时，break
        last=0;
        for(int i=0;i<s.size();i++)//将字符串转化为数字
            last*=10,last+=s[i]-'0';

        int now=1;
        while(last!=s.size()){//暴力模拟过程
            now++;
            last=s.size();
            s=get(s);//将处理过程
        }
        cout<<now<<endl;
    }
}
