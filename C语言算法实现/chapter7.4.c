#include<stdio.h>

int main()
{
	char s;
	int i=1;
	printf("Enter phone number: \n");
	while(i<=7)
	{
		scanf("%1c",&s);
		switch(s)
		{
			case 'A':case 'B':case 'C':
			printf("2");i++;break;
			case 'D':case 'E': case 'F':
			printf("3");i++;break;
			case 'G':case 'H':case 'I':
			printf("4");i++;break;
			case 'L':case 'K':case 'J':
			printf("5");i++;break;
			case 'M':case 'N':case 'O':
			printf("6");i++;break;
			case 'P':case 'Q':case 'R':case 'S':
			printf("7");i++;break;
			case 'T':case 'U': case 'V':
			printf("8");i++;break;
			case 'W': case 'X': case 'Y': case 'Z':
			printf("9");i++;break;
			default :
			printf("%c",s);  
		}
		
	}
	return 0;
}








 