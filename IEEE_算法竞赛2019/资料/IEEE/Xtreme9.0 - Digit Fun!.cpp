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
        if(s[0]=='E')break;//����EOFʱ��break
        last=0;
        for(int i=0;i<s.size();i++)//���ַ���ת��Ϊ����
            last*=10,last+=s[i]-'0';

        int now=1;
        while(last!=s.size()){//����ģ�����
            now++;
            last=s.size();
            s=get(s);//���������
        }
        cout<<now<<endl;
    }
}
