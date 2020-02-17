#include<bits/stdc++.h>
using namespace std;
int dx[8]={1,-1,1,-1,0,0,1,-1};
int dy[8]={1,-1,-1,1,1,-1,0,0};
string s[1005];
int vis[1005][1005];
int flag = 0,n,m;
void bfs(int x,int y,char z){
    queue<int> X,Y;
    X.push(x);
    Y.push(y);
    while(!X.empty())
    {
        x=X.front(),y=Y.front();
        X.pop(),Y.pop();
        vis[x][y]=1;
        if(z=='X')
        {
            for(int i=0;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=n)continue;
                if(vis[nx][ny])continue;
                if(s[nx][ny]!=z)continue;
                X.push(nx);
                Y.push(ny);
            }
        }
        else{
            for(int i=4;i<8;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=n){
                    flag=1;
                    continue;
                }
                if(vis[nx][ny])continue;
                if(s[nx][ny]!=z)continue;
                X.push(nx);
                Y.push(ny);
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(vis,0,sizeof(vis));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            cin>>s[i];
        int ans1 = 0,ans2 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]&&s[i][j]=='X')
                {
                    bfs(i,j,'X');
                    ans1++;
                }
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j]&&s[i][j]=='O'){
                    flag=0;
                    bfs(i,j,'O');
                    if(flag==0)ans2++;
                }
            }
        cout<<ans1-ans2<<endl;
    }
}
