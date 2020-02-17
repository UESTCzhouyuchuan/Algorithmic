#include<stdio.h>

int main()
{
	char ch[20]={},sh[20]={};
	int i,j,t,a;
	printf("Enter first word: \n");
	for(i=0;;i++)
	{
		ch[i]=getchar();
		if(ch[i]=='\n')
		break;
		if(ch[i]<'A'||(ch[i]<'a'&&ch[i]>'Z')||ch[i]>'z')
		ch[i]=0;
	}
	printf("Enter second word: \n");
	for(j=0;;j++)
	{
		sh[j]=getchar();
		if(sh[j]=='\n')
		break;
		if(sh[j]<'A'||(sh[j]<'a'&&sh[j]>'Z')||sh[j]>'z')
		sh[j]=0;
	}
	a=i;
	if(i!=j){
		printf("The words are not anagrams.");
		return 0;
	}
	
	
	for(i=0;i<a;i++)
	{ t=0;
		for(j=0;j<a;j++)
		{
			if(ch[i]==sh[j])
			t=1; 
		}
		if(t!=1)
		{
		printf("The words are not anagrams.");
		return 0;	
		}
	}
	
	for(i=0;i<a;i++)
	{
		t=0; 
		for(j =0;j <a;j++)
		{
			if(ch[j]==sh[i])
			t=1; 
		}
		if(t!=1)
		{
		printf("The words are not anagrams.");
		return 0;	
		}
	}
	
	printf("The words are anagrams.");
	return 0;
}


