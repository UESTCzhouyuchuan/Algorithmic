#include<stdio.h>
#include<stdbool.h>

bool is_primer(int n);

int main(void){
	int sum=0;             //记录素数的个数 
	int n;
	printf("Enter n: \n");
	scanf(" %d",&n);
	int i;               //1到n进行遍历
	for(i=1;i<n+1;i++)
	if(is_primer(i))
	sum++;                //是素数sum就加一
	
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
