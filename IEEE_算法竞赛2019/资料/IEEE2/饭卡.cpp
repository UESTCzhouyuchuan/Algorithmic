

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;


int p[1005];
bool dp[1005];
int n,m;

int main () {
	int ans,ans2;
	while (1) {
		scanf("%d",&n);
		if (n==0)
			break;
		for (int i=1;i<=n;i++) {
			scanf("%d",p+i);
		}
		scanf("%d",&m);
		if (m<5) {
			printf("%d\n",m);
			continue;
		}
		m-=5;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		ans=0;
		sort(p+1,p+n+1);
		for (int i=1;i<n;i++) {
			for (int v=m;v>=p[i];v--) {
				if (dp[v-p[i]]) {
					dp[v]=1;
					ans=max(ans,v);
				}
			}
		}
		printf("%d\n",m+5-ans-p[n]);
	}
	return 0;
}

