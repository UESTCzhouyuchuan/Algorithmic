#include <bits/stdc++.h>

using namespace std;

std::default_random_engine generator(time(NULL));  
std::uniform_int_distribution<int> dis(0,2e9);  
auto dice = std::bind(dis,generator);  


int N = 1e4;

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

void go( int cnt ){
	vector < int > rs;
	for(int i = 1 ; i <= cnt ; ++ i) rs.push_back( 1 );
	for(int j = cnt + 1 ; j <= N ; ++ j) rs.push_back( 0 );
	for(int i = 1 ; i <= 5 ; ++ i) random_sort( rs );
	output( rs );
}

int main( int argc , char * argv[] ){
	freopen( "001.in" , "w" , stdout );
	init();
	int Case = 22 ;

	printf("%d\n" , Case);
	vector < int > base;
	for(int i = 1 ; i <= N ; ++ i) base.push_back( i );

	for(int cas = 1 ; cas <= Case ; ++ cas){
		printf("%d\n" , N );
		random_sort( base );
		output( base );
		if( cas == 1 ) go( 100 );
		else if( cas == 2 ) go( N - 100 );
		else if( cas == 3 ) go( 500 );
		else if( cas == 4 ) go( N - 500 );
		else if( cas == 5 ) go( 1e3 );
		else if( cas == 6 ) go( N - 1e3 );
		else if( cas == 7 ) go( 2e3 );
		else if( cas == 8 ) go( N - 2e3 );
		else if( cas == 9 ) go( 3e3 );
		else if( cas == 10 ) go( N - 3e3 );
		else if( cas == 11 ) go( 5e3 );
		else if( cas == 12 ) go( N - 5e3 );
		else if( cas == 13 ) go( N - 1000 );
		else if( cas == 14 ) go( 1000 );
		else if( cas == 15 ) go( 0 );
		else if( cas <= 18 ) go( N / 2 );
		else if( cas <= 20 ) go( Create_random( 0 , 100 ));
		else go( Create_random( 0 , N ));
	}


	return 0;
}