#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char n1[11]={"- -- -----"};
char n2[11]={"|   ||| ||"};
char n3[11]={"|||||  |||"};
char n4[11]={"  ----- --"};
char n5[11]={"| |   | | "};
char n6[11]={"|| |||||||"};
char n7[11]={"- -- -- --"};

int main(void)
{
	char s[9];
	int size,nDigit,nLength,i,j,k;
	do{
		scanf(" %d",&size);
		if(!size)
		break;
		scanf("%s",s);
		nLength=strlen(s);
		for (i = 0 ; i < nLength ; i++)
		{
			nDigit=s[i]-'0';
			printf(" ");
			for (j = 0 ; j < size ; j++)
			{
				printf("%c", n1[nDigit]);
			}
			printf("  ");
		}
		printf("\n");
		for (k = 0 ; k < size ; k++){
		for (i = 0 ; i < nLength ; i++)
		{
			nDigit=s[i]-'0';
			printf("%c", n2[nDigit]);
			for ( j = 0 ; j < size ; j++)
			printf(" ");
			printf("%c", n3[nDigit]);
			printf(" ");
		}
		printf("\n");
		}
		
		printf("\n");
		for (i = 0 ; i < nLength ; i++)
		{
			nDigit=s[i]-'0';
			printf(" ");
			for (j = 0 ; j < size ; j++)
			{
				printf("%c", n4[nDigit]);
			}
			printf("  ");
		}
		printf("\n");
		for (k = 0 ; k < size ; k++){
		for (i = 0 ; i < nLength ; i++)
		{
			nDigit=s[i]-'0';
			printf("%c", n5[nDigit]);
			for ( j = 0 ; j < size ; j++)
			printf(" ");
			printf("%c", n6[nDigit]);
			printf(" ");
		}
		printf("\n");
		}
		printf("\n");
		for (i = 0 ; i < nLength ; i++)
		{
			nDigit=s[i]-'0';
			printf(" ");
			for (j = 0 ; j < size ; j++)
			{
				printf("%c", n7[nDigit]);
			}
			printf("  ");
		}
		printf("\n");
		 
	}while(1);
	return 0;
}
