#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn][maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    int sum = 0;
    for(int i=1;i<=n;i++)
        sum+=a[i][i];
    vector<int>ans;
    int sum2=0;
    for(int i=1;i<=n;i++)
        sum2+=a[i][n-i+1];
    if(sum2!=sum)ans.push_back(0);
    for(int i=1;i<=n;i++){
        sum2=0;
        for(int j=1;j<=n;j++)
            sum2+=a[i][j];
        if(sum2!=sum)ans.push_back(i);
    }
    for(int i=1;i<=n;i++){
        sum2=0;
        for(int j=1;j<=n;j++)
            sum2+=a[j][i];
        if(sum2!=sum)ans.push_back(-i);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
}
