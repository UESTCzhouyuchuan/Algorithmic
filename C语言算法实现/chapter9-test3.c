#include<stdio.h>
#include<ctype.h>
 
int xinxin(char ch)
{
	ch=tolower(ch);
	if(ch<='z'&&ch>='a')
	return (ch+7)%26+1;
	else 
	return 0;
}

int main()
{
	char ch[20];
	int i=0,j;
	int n;
	printf("Please input a line of characters:\n");
	do{
		ch[i]=getchar();
		i++;
	}while(ch[i-1]!='\n');
	for(j=0;j<i-1;j++)
	{
		n=xinxin(ch[j]);
		if(n==0)
		printf("This character is not a letter.\n");
		else 
		printf("The location of %c is: %d\n",ch[j],n);
		
	}
	return 0;
}