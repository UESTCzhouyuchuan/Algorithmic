#include<stdio.h>

int main()
{
	char ch[100];
	int i,j,b[10],t=1;
	printf("Enter a sentence: \n");
	ch[0]=' ';
	for(i=1;;i++)
	{
		ch[i]=getchar();
		if(ch[i]=='!'||ch[i]=='?'||ch[i]=='.')break;
		if(ch[i]==' ')
		b[t++]=i; 
	}
	b[0]=0;
	b[t]=i;
	printf("Reversal of sentence:");
	for(t=t-1;t>=0;t--)
	{
		for(j=b[t]+1;j<=b[t+1];j++)
		{
			printf("%c",ch[j-1]);
		}
	}
	printf("%c",ch[i]);
	return 0;
} 

