#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
using namespace __gnu_pbds;
using namespace std;

const int maxn = 10000 + 15;

int n , d , a[maxn] , b[maxn] , c[maxn] , sum[maxn];
long long x;
pair < int , int > p[maxn];
vector < int > vi;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> rbt; 
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> :: iterator it ;


int main( int argc,char *argv[] ){
	freopen( "001.in" , "r" , stdin );
	freopen( "001.out" , "w" , stdout );
	int Case;
	scanf("%d",&Case);
	while(Case--){
		scanf("%d",&n);
		vi.clear();
		rbt.clear();
		for(int i = 0 ; i < n ; ++ i) c[i] = 0;
		for(int i = 0 ; i < n ; ++ i) scanf("%d" , a + i);
		for(int i = 0 ; i < n ; ++ i) scanf("%d" , b + i);
		for(int i = 0 ; i < n ; ++ i) p[i].first = a[i] , p[i].second = i;
		sort( p , p + n );
		for(int i = 0 ; i < n ; ++ i) if( b[i] ) vi.push_back( i );
		sum[0] = b[0];
	    for(int i = 1 ; i < n ; ++ i) sum[i] = sum[ i - 1 ] + b[i];
		for(int i = 0 ; i < n ; ++ i) rbt.insert( i );
		for(int i = n - 1 ; i >= 0 ; -- i){
			int idx = p[i].second;
			int num1 = sum[n - idx];
			int num2 = rbt.size() - rbt.order_of_key( idx );
			if( d <= 500 && num1 < num2 ){
				for(auto it : vi){
					if( it + idx > n ) break;
					c[it + idx] = max( c[it + idx] , p[i].first );
				}
			}else{
				it = rbt.lower_bound( idx );
				while( it != rbt.end() ){
					int pos = *it;
					int dis = pos - idx;
					if( b[dis] ){
						c[pos] = max( c[pos] , p[i].first);
						it = rbt.erase( it );
					}else ++ it;
				}
			}
		}
		for(int i = 0 ; i < n ; ++ i) printf("%d\n" , c[i]);
	}
	return 0;
}