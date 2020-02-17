#include<bits/stdc++.h>
using namespace std;

double x1,y1,x2,y2;
double lx,ly,nx,ny;
int cnt=0;
double X[250],Y[250];
double len[250];
double dp[250][250];
double dis(double x,double y,double xx,double yy){
    return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
int main()
{
    for(int i=0;i<250;i++)
        for(int j=0;j<250;j++)
            if(i==j)dp[i][j]=0;
            else dp[i][j]=1e9;
    cin>>x1>>y1>>x2>>y2;
    cnt++;X[0]=x1,Y[0]=y1;
    while(cin>>nx>>ny){
        int st=cnt;
        len[cnt]=0;
        X[cnt]=nx,Y[cnt]=ny;
        for(int i=0;i<cnt;i++)
        {
            dp[cnt][i]=min(dp[cnt][i],dis(nx,ny,X[i],Y[i])/1000.0*6);
            dp[i][cnt]=min(dp[i][cnt],dis(nx,ny,X[i],Y[i])/1000.0*6);
        }
        cnt++;
        while(cin>>lx>>ly){
            if(lx==-1&&ly==-1)break;
            swap(lx,nx);
            swap(ly,ny);
            len[cnt]=dis(lx,ly,nx,ny)+len[cnt-1];
            X[cnt]=nx,Y[cnt]=ny;
            for(int i=0;i<cnt;i++)
            {
                dp[cnt][i]=min(dp[cnt][i],dis(nx,ny,X[i],Y[i])/1000.0*6);
                dp[i][cnt]=min(dp[i][cnt],dis(nx,ny,X[i],Y[i])/1000.0*6);
            }
            for(int i=st;i<cnt;i++)
            {
                dp[cnt][i]=min(dp[cnt][i],(len[cnt]-len[i])/4000.0*6);
                dp[i][cnt]=min(dp[i][cnt],(len[cnt]-len[i])/4000.0*6);
            }
            cnt++;
        }
    }
    X[cnt]=x2,Y[cnt]=y2;
    for(int i=0;i<=cnt;i++){
        for(int j=0;j<=cnt;j++){
            if(i==j)dp[i][j]=0;
            else dp[i][j]=min(dp[i][j],dis(X[i],Y[i],X[j],Y[j])/1000.0*6);
        }
    }
    for(int k=0;k<=cnt;k++){
        for(int j=0;j<=cnt;j++){
            for(int i=0;i<=cnt;i++)
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        }
    }
    printf("%.0f\n",dp[0][cnt]);
}
