#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 15;
const int inf = 2e9;

int N , Q , a[maxn];

struct Sgtree{
	struct node{
		int l , r ;
		int val[16] , lazy;

		void update( const node & a , const node & b){
			int i = 1 , j = 1;
			for( int v = 1 ; v <= 15 ; ++ v){
				if( a.val[i] < b.val[j] ) val[v] = a.val[i ++ ];
				else val[v] = b.val[j ++ ];
			}
		}

		void Init( int x = 0 , int f = 1 ){
			int ed = min( 15 , r - l + 1 );
			for(int i = 1 ; i <= ed ; ++ i) val[i] = x;
			for(int i = ed + 1 ; i <= 15 ; ++ i) val[i] = inf;
			if( f ) lazy = x;
		}

	}tree[maxn << 2];

	inline void push_up( int o ){
		tree[o].update( tree[o << 1] , tree[o << 1 | 1] );
	}

	inline void push_down( int o ){
		if(tree[o].lazy != inf){
			tree[o << 1].Init( tree[o].lazy );
			tree[o << 1 | 1].Init( tree[o].lazy );
			tree[o].lazy = inf;
		}
	}

	void Build( int l , int r , int o ){
		tree[o].l = l , tree[o].r = r , tree[o].lazy = inf;
		if( r > l ){
			int mid = l + r >> 1;
			Build( l , mid , o << 1 );
			Build( mid + 1 , r , o << 1 | 1 );
			push_up( o );
		}else tree[o].Init( a[l] , 0 );
	}

	void update( int ql , int qr , int x , int o ){
		int l = tree[o].l , r = tree[o].r;
		if( ql <= l && r <= qr ) tree[o].Init( x );
		else{
			int mid = l + r >> 1;
			push_down( o );
			if( ql <= mid ) update( ql , qr , x , o << 1 );
			if( qr > mid ) update( ql , qr , x , o << 1 | 1 );
			push_up( o );
		}
	}

	node ask(int ql , int qr , int o){
		int l = tree[o].l , r = tree[o].r;
		if( ql <= l && r <= qr ) return tree[o];
		else{
			int mid = l + r >> 1;
			int ns = tree[o].lazy != inf;
			push_down( o );
			node ls , rs ;
			int label = 0;
			if( ql <= mid ){
				ls = ask( ql , qr , o << 1 );
				label = 1;
			}
			if( qr > mid ){
				rs =  ask( ql , qr , o << 1 | 1 );
				label |= 2;
			}
			if( ns ) push_up( o );

			if( label == 1 ) return ls;
			else if( label == 2 ) return rs;
			else{
				node ans;
				ans.update( ls , rs);
				return ans;
			}

		}
	}

}Sgtree;

int main( int argc , char *argv[] ){
	freopen( "001.in" , "r" , stdin );
	freopen( "001.out" , "w" ,stdout );
	int Case ; 
	scanf("%d",&Case);
	while(Case--){
		scanf("%d%d",&N,&Q);
		for(int i = 1 ; i <= N ; ++ i) scanf("%d" , a + i);
		Sgtree.Build( 1 , N , 1 );
		while(Q--){
			int x , l , r , k;
			scanf("%d%d%d%d",&x,&l,&r,&k);
			assert( l <= r );

			if( x == 1 ){
				Sgtree.update( l , r , k , 1 );
				assert( k <= 1e9 );
			}
			else{
				assert( k <= min( 15 , r - l + 1 ));
				Sgtree::node rs = Sgtree.ask( l , r , 1 );
				printf("%d\n" , rs.val[ k ] );
			}
		}
	}
	return 0;
}