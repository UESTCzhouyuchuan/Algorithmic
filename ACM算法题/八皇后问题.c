//回溯法 八皇后问题
#include <stdio.h>
#define N 10
int cur;
int counter=0; 
void search(int cur);
int s[N],a[N];
int n;
int main(void){

	while (scanf("%d",&n)==1)
	{
		counter=0;
		search(0);
		if (counter==0)
		printf("No solution\n");
	}
	return 0;
} 

void search (int cur)
{
	int i,j;
	if (cur==n)
	{
		for (i=0;i<n;i++)
		printf("%d ",s[i]);
		counter++;
		printf("\n");
	}
	else
	{
		for (i=0;i<n;i++)
		{
		s[cur]=i+1;
		for(j=0;j<cur;j++)
		if (s[j]==s[cur]||j-cur==s[j]-s[cur]||j-cur==s[cur]-s[j]) 
			break;
			if (j==cur)
			search(cur+1);
		}
	}
}
