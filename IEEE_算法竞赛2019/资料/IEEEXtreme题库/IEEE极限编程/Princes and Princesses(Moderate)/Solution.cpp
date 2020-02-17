#include <bits/stdc++.h>

using namespace std;

const int mod = 772002 + 233;
int N , K , dp[1005][35];

inline void update( int & x , int v ){
	x += v;
	if( x >= mod ) x -= mod;
}

inline int mul( int a , int b ){ return 1LL * a * b % mod ;}

int main( int argc , char * argv[] ){
	freopen( "001.in" , "r" , stdin );
	freopen( "001.out" , "w" , stdout );
	int Case;
	scanf("%d",&Case);
	while(Case--){
		scanf("%d%d",&N,&K);
		memset( dp , 0 , sizeof( dp ) );
		dp[0][0] = 1;
		for(int i = 0 ; i < N ; ++ i)
			for(int j = 0 ; j <= K ; ++ j)
				if( dp[i][j] ){
					update( dp[i + 1][j + 1] , mul( dp[i][j] , K - j ) );
					update( dp[i + 1][j] , mul( dp[i][j] , j ));
				}
		printf("%d\n" , dp[N][K] );
	}
	return 0;
}