#include<stdio.h>
#include<stdlib.h>
#define M 10
int LongNumMod (int sum,char*s, int mod);
int main(void) {
	char*s= (char*)malloc(sizeof(char)*M);
	char ch;								//��¼����
	int i=0,mod;							//��¼�ַ����ĳ��ȣ�����realloc 
	printf("Enter the mod number: \n");
	scanf(" %d",&mod);
	printf ("Enter the long number: \n");
    scanf(" %c",&ch);
	while (ch!='\n')
	{
		s[i++]= ch;
		if (i%M==0)
		s=(char*)realloc(s,sizeof(char)*(i+M));
		ch=getchar(); 
	}
	s[i]='\0';
	int sum=0;
	printf("%s mod %d equal %d\n",s,mod,LongNumMod(sum,s,mod));
	return 0;
	
}
int LongNumMod (int sum,char*s, int mod){
	return (*(s) ?(LongNumMod((sum*10+*s-'0')%mod,s+1,mod)):(sum%mod));
}
