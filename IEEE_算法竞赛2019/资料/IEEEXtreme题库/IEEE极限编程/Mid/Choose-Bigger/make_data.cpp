#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("000.in","w",stdout);
    srand(time(NULL));
    int t = 10;
    cout<<t<<endl;
    for(int tt=1;tt<=5;tt++)
    {
        int n = 100,m = 5000,k = 5000;
        cout<<n<<" "<<m<<" "<<k<<endl;
        for(int i=1;i<=m;i++)
        {
            int x = rand()%100+1;
            int y = rand()%100+1;
            if(x==y)
                x=1,y=2;
            cout<<x<<" "<<y<<endl;
        }
        for(int i=1;i<=k;i++)
        {
            int x = rand()%100+1;
            int y = rand()%100+1;
            if(x==y)
                x=1,y=2;
            cout<<x<<" "<<y<<endl;
        }
    }
    for(int tt=1;tt<=5;tt++)
    {
        int n = 100,m = 30,k = 5000;
        cout<<n<<" "<<m<<" "<<k<<endl;
        for(int i=1;i<=m;i++)
        {
            int x = rand()%100+1;
            int y = rand()%100+1;
            if(x==y)
                x=1,y=2;
            cout<<x<<" "<<y<<endl;
        }
        for(int i=1;i<=k;i++)
        {
            int x = rand()%100+1;
            int y = rand()%100+1;
            if(x==y)
                x=1,y=2;
            cout<<x<<" "<<y<<endl;
        }
    }
}
