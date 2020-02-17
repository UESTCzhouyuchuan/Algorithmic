#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define N 100
int n,m;
int counter;
char ch[N];
bool is_diff(char* ch);
bool search(int depth);
int main(void){
	
	while (scanf ("%d %d",&m,&n)==2)
	{
		 counter=0;
		 search(0);
		 
	} 
	return 0; 
}
bool is_diff(char* ch){
	int i,j,t,k;
	for (i=0;ch[i+1]!='\0';i++)
	{
		for (j=i+1;ch[j]!='\0';j++)
		{
			if (ch[i]==ch[j]){
				for (t=i+1,k=j+1;t<j;t++,k++)
				{
					if(ch[t]!=ch[k])
					break;
				}
				if (t==j)
				return false;
				
			}
		}
	}
	return true;
}
bool search(int depth){
	int i;
	if (counter==m)
	{
		puts(ch);
		return 1;
	}
	else
	{
		for (i=0;i<n;i++)
		{
			ch[depth]='A'+i;
			ch[depth+1]='\0';
			if (is_diff(ch))
			{
				counter++;
				if(search(depth+1))
				return 0;
			}
		}
		return 0;
	}
}

