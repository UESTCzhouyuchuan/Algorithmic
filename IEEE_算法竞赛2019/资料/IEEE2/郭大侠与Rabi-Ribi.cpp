#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
	int t,w;
}e[100005];

struct cmp1{
	bool operator ()(node a,node b){
		return a.w<b.w;//最大值优先
	}
};

bool cmp2(node a,node b){
    return a.t>b.t;//最大值优先
}

priority_queue<node,vector<node>,cmp1> q;
int n,ans,point;

int main(){
//	freopen("01.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&e[i].t);
	for(int i=1;i<=n;i++) scanf("%d",&e[i].w);
	sort(e+1,e+n+1,cmp2);


	int i=5000;point=1;
	while(i>0){
		while(e[point].t>=i){
			q.push(e[point++]);
		}
		if(!q.empty()) ans+=q.top().w,q.pop();
		i--;
	}

	printf("%d\n",ans);
	return 0;
}

