#include<stdio.h>
#define MAX 100
int main(void)
{
	char ch[MAX],*p= ch;
	printf("Enter a message: \n");
	while((*p++=getchar())!='\n');
	printf("Reversal is: ");
	for(p=p-2;p>=ch;p--)
	printf("%c",*p);
	return 0;
	
}
