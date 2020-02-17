

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int N = 100005;
int f[N*2+5];
void Init()
{
    for(int i = 1;i <= N*2;i++)
        f[i] = i;
}
int getf(int t)
{
    if(t == f[t])
        return t;
    f[t] = getf(f[t]);
    return f[t];
}
void merge(int u,int v)
{
    int t1 = getf(f[u]);
    int t2 = getf(f[v]);
    if(t1 != t2)
        f[t2] = t1;
}
int main()
{
    int n;
    cin >> n;
    Init();
    int B,ch;
    for(int i = 1;i <= n;i++)
    {
        cin >> B >> ch;
        if(ch == 1)
        {
            merge(i,B);
            merge(i+N,B+N);
        }
        else
        {
            merge(i,B+N);
            merge(i+N,B);
        }
    }

    bool flag = false;
    for(int i = 1;i <= n;i++)
    {
        if(getf(i) == getf(i+N))
        {
            flag = true;
            break;
        }
    }
    if(flag)
        printf("One face meng bi\n");
    else
        printf("Time to show my power\n");
    return 0;
}

