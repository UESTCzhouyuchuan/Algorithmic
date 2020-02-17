#include <bits/stdc++.h>

using namespace std;

const int mod = 772002 + 233;

string N , K ;

string BigINTtoBinary(string n){  
    string result="";  
    string temp="temp";  
    while(temp.length()>0)  
    {  
        temp="";  
        int i=0;  
        char ch;  
        while(i<n.length())  
        {  
            ch=n[i]-'0';  
            if(ch>=2){  
                temp+=static_cast<char>(ch/2+'0');  
            }  
            else if(ch==0||ch==1){  
                if(temp.length()>0)  
                    temp+='0';  
            }  
  
            if(ch%2==1&&i<n.length()-1){  
                n[i+1]+=10;  
            }  
            i++;  
        }
        result=static_cast<char>( (ch&1) +'0')+result;  
        n=temp;  
    }
    return result;  
}

inline void update( int & x , int v ){
	x += v;
	if( x >= mod ) x -= mod;
}

int dp[2000][2][2][2][2];

int solve(){
	memset( dp , 0 , sizeof( dp ) );
	dp[N.size()][0][0][0][0] = 1;
	// i < j;
	for(int i = N.size() ; i > 0 ; -- i)
		for(int f1 = 0 ; f1 < 2 ; ++ f1)
			for(int f2 = 0 ; f2 < 2 ; ++ f2)
				for(int f3 = 0 ; f3 < 2 ; ++ f3)
					for(int f4 = 0 ; f4 < 2 ; ++ f4){
						int ed1 = f1 ? 1 : (N[ i - 1 ] - '0');
						int ed2 = f2 ? 1 : (N[ i - 1 ] - '0');
						for(int add1 = 0 ; add1 <= ed1 ; ++ add1)
							for(int add2 = 0 ; add2 <= ed2 ; ++ add2){
								int newf1 = f1 | ( add1 < ed1 );
								int newf2 = f2 | ( add2 < ed2 );
								if( !f3 && add1 > add2 ) continue;
								int newf3 = f3 | ( add1 < add2 );
								int sa = add1 ^ add2;
								if( !f4 && (K[i - 1] - '0') > sa ) continue;
								int newf4 = f4 | ( sa > (K[i - 1] - '0') );
								update( dp[i - 1][newf1][newf2][newf3][newf4] , dp[i][f1][f2][f3][f4] );
							}
					}
	int res = 0;
	for(int i = 0 ; i < 2 ; ++ i)
		for(int j = 0 ; j < 2 ; ++ j)
			for(int k = 0 ; k < 2 ; ++ k)
				update( res , dp[0][i][j][1][k] );
	return res;
}


int main( int argc , char * argv[] ){
	freopen( "001.in" , "r" , stdin );
	freopen( "001.out" , "w" , stdout );
	int Case;
	cin >> Case;
	while(Case--){
		cin >> N >> K ;
		N = BigINTtoBinary( N );
		K = BigINTtoBinary( K );
		reverse(N.begin(),N.end());
		reverse(K.begin(),K.end());
		string * fst = & N , *scd = &K;
		if( fst->size() > scd->size() ) swap( fst , scd );
		while(fst->size() < scd->size()) fst->push_back( '0' );
		cout << solve() << endl;
	}
	return 0;
}