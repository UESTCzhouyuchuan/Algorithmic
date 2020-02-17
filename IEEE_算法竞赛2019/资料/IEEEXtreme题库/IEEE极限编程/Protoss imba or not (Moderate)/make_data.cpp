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

string Create( int len ){
	string rs;
	for(int i = 0 ; i < len ; ++ i){
		if( i == 0 ) rs.push_back( '0' + Create_random( 1 , 9 ) );
		else rs.push_back( Create_random( 0 , 9 ) + '0' );
	}
	return rs;
}

void init(){
	srand(time(NULL));	
}

int main( int argc , char * argv[] ){
	freopen( "001.in" , "w" , stdout );
	init();

	int Case = 2000 ;

	cout << Case << endl;

	for(int cas = 1 ; cas <= Case ; ++ cas){
		int len = 50;
		if( cas <= 5 ){
			len = 100 + rand()%10;
			cout << Create( len ) << endl;
			cout << Create( len ) << endl;
		}else if( cas <= 50 ){
			len = 200 + rand()%10;
			cout << Create( len ) << endl;
			cout << Create( 1 + rand()%10 ) << endl;
		}else if( cas <= 100 ){
			len = 200 + rand()%10;
			cout << Create( len ) << endl;
			cout << Create( 500 ) << endl;
		}else if( cas <= 200 ){
			len = 400 + rand()%10;
			cout << Create( len ) << endl;
			cout << Create( 1 + rand()%300 ) << endl;
		}else if( cas <= 250 ){
			len = 500;
			cout << Create( len ) << endl;
			cout << Create( 1 + rand()%400 ) << endl;
		}else if( cas <= 300 ){
			len = 500;
			cout << Create( len ) << endl;
			cout << Create( len ) << endl;
		}else if( cas <= 350 ){
			len = 500;
			cout << Create( len ) << endl;
			cout << Create( 100 + rand()%200 ) << endl;
		}else if( cas <= 351 ){
			cout << 0 << endl << 0 << endl;
		}else if( cas <= 390 ){
			len = 388;
			cout << Create( 388 ) << endl;
			cout << Create( 388 ) << endl;
		}else if( cas <= 391){
			for(int i = 1 ; i <= 499 ; ++ i) cout << 9 ;
			cout << 8 << endl;
			for(int i = 1 ; i <= 500 ; ++ i) cout << 9 ;
			cout << endl;
		}else if( cas <= 500){
			len = 500;
			cout << Create( len ) << endl;
			cout << Create( Create_random( 1 , 100 ) ) << endl;
		}else if( cas <= 600 ){
			len = 500;
			cout << Create( len ) << endl;
			cout << Create( Create_random( 100 , 200 ) ) << endl;
		}else if( cas <= 700 ){
			len = 500;
			cout << Create( len ) << endl;
			cout << Create( Create_random( 200 , 300 ) ) << endl;
		}else if( cas <= 800 ){
			len = 500;
			cout << Create( len ) << endl;
			cout << Create( Create_random( 300 , 400 ) ) << endl;
		}else if( cas <= 900 ){
			len = 500;
			cout << Create( len ) << endl;
			cout << Create( Create_random( 400 , 500 ) ) << endl;
		}else{
			len = 500;
			cout << Create( len ) << endl;
			cout << Create( Create_random( 1 , 500 ) ) << endl;
		}
	}

	return 0;
}