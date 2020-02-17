//一个数的乘2组成不变特性 
#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int main(void){
	char a[MAX]={},b[MAX]={};
	int A[10]={},B[10]={};
	char ch;
	int i,j;
	for(i=0;(ch=getchar())!='\n';i++)
	a[i]=ch%'0';
	b[0]=a[0]*2;
	for(j=1;j<i;j++){
		if(a[j]*2>=10)
		{
			b[j-1]+=a[j]*2/10;
			b[j]=a[j]*2%10;
		}
		else{
			b[j]=a[j]*2;
		}
	}
	if(a[0]>=5){
		printf("No\n");
		for(j=0;j<i;j++)
		printf("%d",b[j]);
		return 0;
	}
	for(j=0;j<i;j++){
		A[a[j]]++;
		B[b[j]]++;
	}
	for(j=0;j<10;j++)
	if(A[j]!=B[j]){
		printf("No\n");
		for(j=0;j<i;j++)
		printf("%d",b[j]);
		return 0;
	}
	printf("Yes\n");
	for(j=0;j<i;j++)
		printf("%d",b[j]);
	return 0;
}
