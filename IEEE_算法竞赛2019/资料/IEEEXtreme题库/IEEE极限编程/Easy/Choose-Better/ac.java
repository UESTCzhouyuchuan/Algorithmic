import java.io.*;
import java.util.*;
import java.math.*;
import java.util.Arrays;  

class he implements Comparable<he>  
{  
    int x,y;  
   /*因为上面指定了类型<he>，所以此处可以直接(he A) 
   *否则要写成(Object A)，再强制转换成he类型：((he)A).x 
   */  
    public int compareTo(he a)  
    {    
        if(this.x-a.x!=0)   
        return a.x-this.x;  
        else return a.y-this.y;  
    }  
}  
public class Main
{
	public static void solve()
	{
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		he d[][]=new he[3][1000005];  
		for(int i=0;i<3;i++){
			for(int j=0;j<n;j++){
				d[i][j] = new he();
				d[i][j].x=in.nextInt();
				d[i][j].y=j;
			}
		}
		for(int i=0;i<3;i++)
			Arrays.sort(d[i],0,n);
		for(int i=0;i<3;i++){
			for(int j=0;j<n;j++){
				System.out.printf("%d %d ",d[i][j].x,d[i][j].y);
			}
			System.out.println();
		}
			
		long ans = 0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				for(int k=0;k<3;k++){
					if(d[0][i].y==d[1][j].y)continue;
					if(d[1][j].y==d[2][k].y)continue;
					if(d[0][i].y==d[2][k].y)continue;
					long tmp = d[0][i].x;
					tmp = tmp + d[1][j].x;
					tmp = tmp + d[2][k].x;
					if(ans<tmp)ans=tmp;
				}
			}
		}
		System.out.println(ans);
	}
    public static void main(String[] args)
    {
    	Scanner in = new Scanner(System.in);
    	int t = in.nextInt();
    	for(int ii=0;ii<t;ii++)
    		solve();
    }
}