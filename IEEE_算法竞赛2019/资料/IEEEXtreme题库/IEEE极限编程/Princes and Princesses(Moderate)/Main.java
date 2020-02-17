import java.io.*;
import java.math.*;
import java.util.*;


public class Main
{
	static int dp[][] = new int[1005][32];
	static int mod = 772002 + 233;

	static int mul( int x , int y ){
		return (int)(((long)x * (long)y) % mod);
	}

	public static void main(String argv[]) throws Exception
    {
    	Scanner cin = new Scanner(System.in);
    	try{cin=new Scanner(new FileInputStream("001.in"));}catch(Exception e){}
    	PrintStream ps = new PrintStream(new FileOutputStream("java001.out"));  
        System.setOut(ps);  
        int Case = cin.nextInt();
        while(Case > 0){
        	int N = cin.nextInt() , K = cin.nextInt();
        	for(int i = 0 ; i <= N ; ++ i) Arrays.fill( dp[i] , 0 );
        	dp[0][0] = 1;
			for(int i = 0 ; i < N ; ++ i)
				for(int j = 0 ; j <= K ; ++ j)
					if( dp[i][j] > 0 ){
						dp[i + 1][j + 1] += mul( dp[i][j] , K - j ) ;
					    dp[i + 1][j] += mul( dp[i][j] , j );
					    if( dp[i + 1][j + 1] >= mod ) dp[i + 1][j + 1] -= mod;
					    if( dp[i + 1][j] >= mod ) dp[i + 1][j] -= mod;
					}
			System.out.println( dp[N][K] );
        	--Case;
        }
    }
}