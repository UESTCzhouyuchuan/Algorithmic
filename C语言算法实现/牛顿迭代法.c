#include<stdio.h>


double pow(double,int);
double absolute_number(float);
int main(void)
{
	int n,point;//底数 指数 
	double result=1.0;
	double tempt=0;
	printf("Enter a number that you want get its actual value: ");
	scanf("%d %d",&n,&point);
	do{
		tempt=result;
		result=result-(pow(result,point)-n)/((point)*pow(result,point-1));//牛顿拉弗森公式， 
	}while(absolute_number(result-tempt)>(1e-5));
	printf("%f",result);
	return 0;
	 
}
double absolute_number(float n)
{
	if(n>0)
	return n;
	else
	return -n;
}
double pow(double x,int n){
	
return n==0?1:x*pow(x,n-1);	
}

