#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("000.in","w",stdout);
    srand(time(NULL));
    int t = 10;
    cout<<t<<endl;
    for(int j=1;j<=6;j++)
    {
        int n = 100000;
        cout<<n<<endl;
        for(int i=1;i<=n;i++)
            cout<<rand()%100000+1<<" ";
        cout<<endl;
        for(int i=1;i<=n;i++)
            cout<<rand()%1000000+1<<" ";
        cout<<endl;
        for(int i=1;i<=n;i++)
            cout<<rand()%100000+1<<" ";
        cout<<endl;
    }
    cout<<"3"<<endl;
    cout<<"1000000000 1000000000 1000000000"<<endl;
    cout<<"1000000000 1000000000 1000000000"<<endl;
    cout<<"1000000000 1000000000 1000000000"<<endl;
    cout<<"3"<<endl;
    cout<<"1 2 3"<<endl;
    cout<<"1 2 3"<<endl;
    cout<<"1 2 3"<<endl;
    cout<<"10"<<endl;
    cout<<"1 2 3 4 5 6 7 8 9 10"<<endl;
    cout<<"1 2 3 4 5 6 7 8 9 10"<<endl;
    cout<<"1 2 3 4 5 6 7 8 9 1"<<endl;
    cout<<"100000"<<endl;
    for(int i=0;i<3;i++)cout<<"1000000000 ";
    for(int i=0;i<100000-3;i++)cout<<rand()%123123+1<<" ";cout<<endl;
    for(int i=0;i<3;i++)cout<<"1000000000 ";
    for(int i=0;i<100000-3;i++)cout<<rand()%123123+1<<" ";cout<<endl;
    for(int i=0;i<3;i++)cout<<"1000000000 ";
    for(int i=0;i<100000-3;i++)cout<<rand()%123123+1<<" ";cout<<endl;
}
