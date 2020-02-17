import java.io.*;
import java.math.*;
import java.util.*;


public class Main
{
	static int dp[][][][][] = new int[2005][2][2][2][2];
	static int mod = 772002 + 233;

	static int mul( int x , int y ){
		return (int)(((long)x * (long)y) % mod);
	}

	static int cmp( int x , int y ){
		if( x < y ) return 1;
		return 0;
	}

	public static void main(String argv[]) throws Exception
    {
    	Scanner cin = new Scanner(System.in);

    	long startMili=System.currentTimeMillis();// 当前时间对应的毫秒数

        try{cin=new Scanner(new FileInputStream("001.in"));}catch(Exception e){}
    	PrintStream ps = new PrintStream(new FileOutputStream("001.out"));  
        System.setOut(ps);  
        int Case = cin.nextInt();
        while(Case > 0){
	    	BigInteger X = cin.nextBigInteger();
	    	StringBuilder N = new StringBuilder(X.toString(2));
	    	X = cin.nextBigInteger();
	    	StringBuilder K = new StringBuilder(X.toString(2));
	    	int extra = Math.abs( N.length() - K.length() );
	    	String Add = new String();
	    	for(int i = 0 ; i < extra ; ++ i) Add += '0';
	    	if(N.length() < K.length()) N.insert( 0 , Add );
		    else K.insert( 0 , Add );
		    N.reverse(); K.reverse();
		    for(int i = 0 ; i <= N.length() ; ++ i)
		    	for(int f1 = 0 ; f1 < 2 ; ++ f1)
		    		for(int f2 = 0 ; f2 < 2 ; ++ f2)
		    			for(int f3 = 0 ; f3 < 2 ; ++ f3)
		    				for(int f4 = 0 ; f4 < 2 ; ++ f4)
		    					dp[i][f1][f2][f3][f4] = 0;
		    dp[N.length()][0][0][0][0] = 1;
	    	for(int i = N.length() ; i > 0 ; -- i)
				for(int f1 = 0 ; f1 < 2 ; ++ f1)
					for(int f2 = 0 ; f2 < 2 ; ++ f2)
						for(int f3 = 0 ; f3 < 2 ; ++ f3)
							for(int f4 = 0 ; f4 < 2 ; ++ f4){
								int ed1 = f1 > 0 ? 1 : (N.charAt( i - 1 ) - '0');
								int ed2 = f2 > 0 ? 1 : (N.charAt( i - 1 ) - '0');
								for(int add1 = 0 ; add1 <= ed1 ; ++ add1)
									for(int add2 = 0 ; add2 <= ed2 ; ++ add2){
										int newf1 = f1 | ( cmp(add1 , ed1) );
										int newf2 = f2 | ( cmp(add2 , ed2) );
										if( f3 == 0 && add1 > add2 ) continue;
										int newf3 = f3 | ( cmp(add1 , add2) );
										int sa = add1 ^ add2;
										if( f4 == 0 && (K.charAt(i - 1) - '0') > sa ) continue;
										int newf4 = f4 | cmp( K.charAt(i - 1) - '0' , sa );
										dp[i - 1][newf1][newf2][newf3][newf4] += dp[i][f1][f2][f3][f4];
										if( dp[i - 1][newf1][newf2][newf3][newf4] >= mod ) dp[i - 1][newf1][newf2][newf3][newf4] -= mod;
									}
							}
			int res = 0;
			for(int i = 0 ; i < 2 ; ++ i)
				for(int j = 0 ; j < 2 ; ++ j)
					for(int k = 0 ; k < 2 ; ++ k){
						res += dp[0][i][j][1][k];
						if( res >= mod ) res -= mod;
					}
			System.out.println( res );
        	--Case;
        }

        long EndMill=System.currentTimeMillis();// 当前时间对应的毫秒数
       // System.out.printf("Time use is ");
       // System.out.println(EndMill - startMili);
    }
}