#include<stdio.h>

void separate(double x,long*zheng,double*xiao)
{
	*zheng=(long)x;
	*xiao=x-*zheng;
}
int main(void)
{
	long zheng;
	double xiao;
	double n;
	printf("Enter a number: \n");
	scanf("%lf",&n);
	if(n>0)printf("sign: +\n");
	if(n<0){
		n=n*(-1);
		printf("sign: -\n");
	}
	if(n==0)printf("sign: \n");
	separate(n,&zheng,&xiao);
	printf("integer part: %ld\nfractional part: %lg\n",zheng,xiao);

	return 0;
}