#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+7;
char s[maxn];
int p[maxn];
int main()
{
    int t;scanf("%d",&t);
    while(t--){
        scanf("%s",s+1);
        int len=strlen(s+1);
        int j=0;
        for(int i=2;i<=len;i++)
        {
            while(j>0&&s[j+1]!=s[i])
                j=p[j];
            if(s[j+1]==s[i])
                j++;
            p[i]=j;
        }
        int tmp=0;
        int first=1;
        printf("%d\n",len-p[len]);
    }
}
