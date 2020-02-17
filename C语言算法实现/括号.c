#include<stdio.h>

int main()
{
	char ch[100],sh;
	int top=0;
	printf("Enter parentheses and/or braces: \n");
	do{
		sh=getchar();
		switch(sh){
			case'(': case'{':
			ch[top]=sh;
			top++;break;
			case')': 
			if(ch[top-1]!='('){
				printf("Parentheses/braces are not nested properly");
				return 0;
			}
			
			else top--;break;
			case'}':
			if(ch[top-1]!='{'){
				printf("Parentheses/braces are not nested properly");
				return 0;
			}
			
			else top--;break;
			case'\n':
			if(top==0)
			{
				printf("Parentheses/braces are nested properly");
				return 0;
			}
			else{
				printf("Parentheses/braces are not nested properly");
				return 0;
			}
			
		}
		
	}while(1);
}