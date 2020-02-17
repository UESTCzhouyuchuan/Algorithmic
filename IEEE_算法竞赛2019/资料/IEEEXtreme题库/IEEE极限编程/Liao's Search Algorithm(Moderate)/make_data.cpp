#include <bits/stdc++.h>

using namespace std;


std::default_random_engine generator(time(NULL));  
std::uniform_int_distribution<int> dis(0,2e9);  
auto dice = std::bind(dis,generator);  


int Create_random( int l , int r ){
	return l + dice() % ( r - l + 1 );
}


void random_sort( vector < int > & v ){
    unsigned seed = std::chrono::system_clock::now ().time_since_epoch ().count ();  
    std::shuffle (v.begin (), v.end (), std::default_random_engine (seed)); 
}

void output( vector < int > & vi ){
	for(int i = 0 ; i < vi.size() ; ++ i){
		if( i ) printf(" ");
		printf("%d" , vi[i]);
	}
	printf("\n");
}


void init(){
	srand(time(NULL));	
}

int main( int argc , char * argv[] ){

	freopen("001.in" , "w" , stdout );

	init();

	int Case = 5;

	cout << Case << endl;

	for(int cas = 1 ; cas <= Case ; ++ cas){
		int N = 1e5 , Q = 1e5;
		cout << N << " " << Q << endl;
		int last = 0;
		for(int i = 1 ; i < N ; ++ i){
			if( i > 1 ) printf(" ");
			int key = Create_random( 1 , 1e3 ) * Create_random( 1 , 1e4 ) + Create_random( 1e6 , 1e8 );
			if( rand()%5000 ){
				printf("%d" , key );
			}else{
				printf("%d" , last );
			}
			last = key;
		}
		printf(" %d\n" , last );
		int k1 = 1e5/2 ;
		int k2 = 1e5/2;
		int conse = 0;
		for(int qq = 1 ; qq <= Q ; ++ qq ){
			if( (rand() % (qq <= 5000 ? 5000 : 10) && abs(k2 - k1) <= 500 && k1 && conse <= 8) || k2 == 0 ){\
				++ conse;
				--k1;
				int l = rand()%N + 1 , r;
				if( l < N / 3 ) r = N / 3 + rand()%( N - N / 3 - l );
				else if( l < N / 2 ) r = N / 2 + rand()%( N - N / 2 - l );
				else{
					r =  l + rand()%( N - l + 1 );
				}
				printf("2 %d %d %d\n" , l , r , min( rand()%15 + 1 , r - l + 1 ) );
			}else{
				conse =0;
				--k2;
				int l = rand()%N + 1 , r;
				if( l < N / 3 ) r = N / 3 + rand()%( N - N / 3 - l );
				else if( l < N / 2 ) r = N / 2 + rand()%( N - N / 2 - l );
				else{
					r =  l + rand()%( N - l + 1 );
				}
				printf("1 %d %d %d\n" , l , r , Create_random( 1 , 1e9 ) );
			}
		}
		assert( k1 == 0 && k2 == 0 );

	}


	return 0;
}