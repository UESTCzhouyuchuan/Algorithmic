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
	freopen( "001.in" , "w" , stdout );
	init();
	int Case = 233;
	printf("%d\n" , Case);

	while(Case--){

		int N = Create_random( 1 , 1000 );
		int K = Create_random( 1 , 30 );
		cout << N << " " << K << endl;

	}


	return 0;
}