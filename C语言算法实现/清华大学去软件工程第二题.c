#include<stdio.h>

int main()
{
	char s1[3][20],s2[3][20];
	int i,j,b[3]={};
	printf("Enter first sentence: ");
	for(i=0;i<3;i++)
	{
	   for(j=0;;j++)
	   {
   		s1[i][j]=getchar();
   		if(s1[i][j]=='\n')
   		break;
   		b[i]=j;
   	}	
	}
	printf("Enter the second sentence:");
	for(i=0;i<3;i++)
	{
	   for(j=0;;j++)
	   {
   		s2[i][j]=getchar();
   		if(s2[i][j]=='\n')
   		{
		   	b[i]=j;break;
		   }
   		
   	}
	}
	   for(i=0;i<3;i++)
	   {
   		for(j=0;j<b[i];j++)
   		{
		   	if(s1[i][j]!=s2[i][j])
		   	{
	   			printf("The different line is %d",i+1);
	   			return 0;
	   		}
		   	
		   }
   	}	
	
    printf("same");
    return 0;
}

