#include<stdio.h> 
#include<ctype.h>
int main()
{
	 char ch[100];
	 int i,j,n;
	 printf("Enter message to be encrypted: ");
	 for(i=0;;i++)
	 {
	 	ch[i]=getchar();
 		if(ch[i]=='\n')
 		break;
 	}
 	ch[0]=tolower(ch[0]);
 	printf("\nEnter shift amount (1-25): ");
	 scanf("%d",&n); 
 	for(j=0;j<i;j++)
 	{
 		if(ch[j]<='z'&&ch[j]>='a'){
		 	ch[j]=(ch[j]+7)%26;
		 	ch[j]=((ch[j]+n)%26+97);
		 	
		 }	
	 }
	 ch[0]=toupper(ch[0]);
	 printf("\nEncrypted message: ");
	 for(j=0;j<i;j++)
	 {
 		printf("%c",ch[j]);
 	}
 	return 0;
} 


