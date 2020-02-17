#include<stdio.h>
#include<stdbool.h>
#define MAX 5
char ch[MAX],n[MAX];
int di[MAX],zh[MAX];
char sh[4]={'c','d','h','s',};
int nu;
char m[13]={'2','3','4','5','6','7','8','9','t','j','q','k','a'};
void paixu(int n[])
{
	int i,j,mid;
	for(i=0;i<5;i++)
	{
		for(j=4;j>i;j--)
		{
			if(n[i]>n[j])
			{
				mid=n[i];
				n[i]=n[j];
				n[j]=mid;
			}
		}
	}
}
bool input(char a,char s)
{
	int k=0,t=0,j; 
	for(j=0;j<13;j++)
	{
		if(a==m[j])
		{
		t=1;
		di[nu]=j;
		break;	
		}
	}
	for(j=0;j<4;j++)
	{
		if(s==sh[j]){
		k=1;
		zh[nu]=j;
		break;	
		}
	}
	if(t==0||k==0){
		printf("Bad card; ignored.\n");
		return true;
	}
	for(j=0;j<nu;j++)
	{
		if(a==n[j]&&s==ch[j])
		{
		printf("Duplicate card; ignored.\n");
		return true;	
		}
	}
	return false;	
}
 
void output(int di[],int zh[])
{
	int t=0,t1=0,i,j,su=0;
	for(i=0;i<5;i++)
	{
		for(j=4;j>i;j--)
		if(ch[i]==ch[j])
		t++;
	}
	for(i=1;i<5;i++)//t代表相等花色的个数 
	{                      //su代表相等等级的个数 
		for(j=4;j>i;j--)    //t1代表相连等级个数 
		{
			if(n[i]==n[j])
			su++;
		}
		
	}
	for(i=0;i<4;i++){
		if((di[i])+1==di[i+1])
	    t1++;
	}
	
	if(t1==4){
		if(t==10)
		printf("Straight flush");
		else printf("shunzhi");
	}
	else if(su==6)
	printf("Shizhanf");
	 else if(su==1)
	 {
	 	if(t==3)
 		printf("Hulu");
 		else printf("Pair.");
 	}
	
	else if(su==3)
	printf("sanzhang");
	else if(su==2)
	printf("Two pairs");
	else
	printf("High card"); 
	
}
int main(void)
{
	int i,j,k;
		for(nu=0;nu<MAX;nu++)
		{
			printf("Enter a card: ");
			scanf(" %c%c",&n[nu],&ch[nu]);
	              if(n[0]=='0')
	              return 0;
			if(input(n[nu],ch[nu]))
			nu--;
		}
		paixu(zh);
		paixu(di);
		int z;
		for(z=0;z<MAX;z++)
		printf("%d,%d\n",zh[z],di[z]);
		output(di,zh);
		
		
	
	return 0;
} 
