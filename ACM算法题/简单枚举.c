#include <stdio.h>
#include <string.h>
//³ý·¨ 789546/01283=62 94736/01528=62 
int counter;
int rot=0;
int a[10],a1[10];
int n;
int Union(int num);

int main(void){
	while (scanf ("%d",&n)==1)
	{
		counter=0;
		rot=0;
		memset(a,0,sizeof(a));
		memset(a1,0,sizeof(a1));
		Union(0); 
		if(rot==0)
		printf("No solution\n");
	}
	return 0;
}
int Union(int num){
	int b,i,t,c;
	

	if (counter==5)
	{
		c=t=num*n;
		if (c<100000)
		{
			
			while (c>0)
			{
				b=c%10;
				if (a[b]||a1[b])break;
				a1[b]=1;
				c/=10;
			}
			
			for (i=0;i<10;i++)
			if (a[i]==0&&a1[i]==0)
			{
			c=1;break;
			}
			memset(a1,0,sizeof(a1));
			if (c==0){
				printf("%05d/%05d=%d\n",t,num,n);
				rot++;
			}
			
			return 0;
		}	
	}
	else
	{
		for(i=0;i<10;i++)
		{
			if (a[i])continue;
			a[i]=1;
			a1[i]=0;
			counter++;
			Union(num*10+i);
			counter--;
			a[i]=0;
			a1[i]=0;
		}
	}
}
