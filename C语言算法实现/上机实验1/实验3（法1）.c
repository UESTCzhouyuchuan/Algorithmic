#include<stdio.h>
#include<stdbool.h>

bool is_primer(int n);

int main(void){
	int sum=0;             //��¼�����ĸ��� 
	int n;
	printf("Enter n: \n");
	scanf(" %d",&n);
	int i;               //1��n���б���
	for(i=1;i<n+1;i++)
	if(is_primer(i))
	sum++;                //������sum�ͼ�һ
	
	printf("The number of primer is %d",sum);
	return 0; 
}
bool is_primer(int n){
	if(n==1)
	return false;
	int i;
	for(i=2;i*i<n+1;i++)
	if(!(n%i))
	return false;
	return true;
}
