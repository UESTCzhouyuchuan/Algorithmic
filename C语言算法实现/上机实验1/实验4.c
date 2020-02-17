#include<stdio.h>

int jiecheng(int num);

int main(void){
	int n;
	printf("Enter n: \n");
	scanf(" %d",&n);
	long sum=0;              //ÇóºÍ 
	int i;                   //±éÀú 
	for(i = 1;i < n+1;i++)
	 sum+=jiecheng(i);
	printf("The sum up: %ld",sum);
	return 0;
} 

int jiecheng(int num){
	return (num==1?1:(num*jiecheng(num-1)));
}
