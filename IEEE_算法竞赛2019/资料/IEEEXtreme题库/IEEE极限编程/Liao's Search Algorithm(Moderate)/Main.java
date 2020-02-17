import java.io.*;
import java.math.*;
import java.util.*;



public class Main
{

	static int N , Q ;
	static int inf = 2000000000;
	static int maxn = 100000 + 15;
	static int a[] = new int[maxn];

	static class SgtreeClass{

		static class Node{
			int l , r ;
			int arr[] = new int[16];
			int lazy;

			void Update( Node a , Node b ){
				int i = 1 , j = 1;
				for(int v = 1 ; v <= 15 ; ++ v){
					if(a.arr[i] < b.arr[j] ) arr[v] = a.arr[i ++ ];
					else arr[v] = b.arr[j ++ ];
				}
			}

			void Modify( int x , int f ){
				int ed = Math.min( r - l + 1 , 15 );
				for(int i = 1 ; i <= ed ; ++ i) arr[i] = x;
				for(int i = ed + 1 ; i <= 15 ; ++ i) arr[i] = inf;
				if( f == 1 ) lazy = x;
			}

		}

		static Node[] tree = new Node[maxn << 2];

		SgtreeClass(){ for(int i = 0 ; i < ( maxn << 2 ) ; ++ i ) tree[i] = new Node(); }

		void Maintain( int o ){
			tree[o].Update( tree[o << 1 ] , tree[o << 1 | 1 ] );
		}

		void Push_down( int o ){
			if( tree[o].lazy != inf ){
				tree[o << 1].Modify( tree[o].lazy , 1 );
				tree[o << 1 | 1].Modify( tree[o].lazy , 1 );
				tree[o].lazy = inf;
			}
		}


		void Build( int l , int r , int o ){
			tree[o].l = l ; tree[o].r = r ; tree[o].lazy = inf;
			if( r > l ){
				int mid = l + r >> 1;
				Build( l , mid , o << 1 );
				Build( mid + 1 , r , o << 1 | 1 );
				Maintain( o );
			}else tree[o].Modify( a[l] , 0 );
		}


		void Modify( int ql , int qr , int v , int o ){
			int l = tree[o].l , r = tree[o].r;
			if( ql <= l && r <= qr ) tree[o].Modify( v , 1 );
			else{
				int mid = l + r >> 1;
				Push_down( o );
				if( ql <= mid ) Modify( ql , qr , v , o << 1 );
				if( qr > mid ) Modify( ql , qr , v , o << 1 | 1 );
				Maintain( o );
			}
		}

		Node ask( int ql , int qr , int o ){
			int l = tree[o].l , r = tree[o].r;
			if( ql <= l && r <= qr ) return tree[o];
			else{
				int mid = l + r >> 1;
				Push_down( o );
				Node ls = new Node() , rs = new Node() ;
				int st = 0;
				if( ql <= mid ){
					st = 1;
					ls = ask( ql , qr , o << 1 );
				}
				if( qr > mid ){
					st += 2;
					rs = ask( ql , qr , o << 1 | 1 );
				}

				Maintain( o );

				if( st < 3 ){
					if( st == 1 ) return ls;
					return rs;
				}

				Node rp = new Node();
				rp.Update( ls , rs );


				return rp;
			}
		}

	}


	public static void main(String argv[]) throws Exception
    {
    	Scanner cin = new Scanner(System.in);

    	try{cin=new Scanner(new FileInputStream("001.in"));}catch(Exception e){}

    	PrintStream ps = new PrintStream(new FileOutputStream("java001.out"));  
        System.setOut(ps);  


    	SgtreeClass Sgtree = new SgtreeClass();
    	int Case = cin.nextInt();

    	while(Case > 0){
    		N = cin.nextInt() ;
    		Q = cin.nextInt();
    		for(int i = 1 ; i <= N ; ++ i) a[i] = cin.nextInt();
    		Sgtree.Build( 1 , N , 1 );
	    	while(Q > 0){
	    		int x = cin.nextInt();
	    		int l = cin.nextInt();
	    		int r = cin.nextInt();
	    		int k = cin.nextInt();
	    		if( x == 1 ) Sgtree.Modify( l , r , k , 1 );
	    		else System.out.println( Sgtree.ask( l , r , 1 ).arr[k] );
	    		--Q;
	    	}
    		-- Case;
    	}
    }
}