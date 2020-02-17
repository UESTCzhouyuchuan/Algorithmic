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
/*��дint delete_array(char s[], int n)������ʵ�����ַ�����s��ɾ���±�Ϊn��Ԫ�أ�ɾ�����±�n���Ԫ������ǰ�����ȱ��ע�����n����Ч�ԣ���ҪԽ�硣


2����дint insert(char s1[], char s2[], int offset)������ʵ�����ַ�����s1�д��±�offset��ʼ�����ַ�����s2����������Ч�ԣ�offset����Խ�磬�Ҳ��������鳤�Ȳ��ܳ���s1����󳤶ȡ�
*/
