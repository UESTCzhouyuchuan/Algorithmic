#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_NUM 100
int delete_array(char s[],int n);
int insert(char s1[],char s2[],int offset);

int main(void)
{
	char str[MAX_NUM+1]="abcdefg";
	char str2[4]="123";
	//delete_array(str,5);
	insert(str,str2,1);
	puts(str);
	
	return 0;
}

int delete_array(char s[],int n){
	if(n>=strlen(s)){
		printf("Of no avail!\n");
		return 0;
	}
	int i;
	for(i = n;i < strlen(s)-1;i++)
	s[i]=s[i+1];
	
	s[i]='\0';
	return 1;
}

int insert(char s1[],char s2[],int offset){
	int num1=strlen(s1),num2=strlen(s2);
	if(offset>=num1){
		printf("Of no avail!\n");
		return 0;
	}
	if(num1+num2>MAX_NUM)
	{
		printf("Overstack!\n");
		return 0;
	}
	int i;
	for(i = num1-1;i>offset;i--){
		s1[i+num2]=s1[i];
	}
	for(i = offset+1;i<offset+num2+1;i++){
		s1[i]=s2[i-offset-1];
	}
	
	s1[num1+num2]='\0';
	return 1;
}
/*编写int delete_array(char s[], int n)函数，实现在字符数组s中删除下标为n的元素，删除后下标n后的元素依次前移填补空缺，注意参数n的有效性，不要越界。


2）编写int insert(char s1[], char s2[], int offset)函数，实现在字符数组s1中从下标offset开始插入字符数组s2，检查参数有效性，offset不能越界，且插入后的数组长度不能超出s1的最大长度。
*/
