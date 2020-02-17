#include<stdio.h>
#define eps (1e-5)
//弦截法求根：x2=x1-f(x1)/(f(x1)-f(x0))  *(x1-x0)
 //周玉川 2017.12.17 
double absolute(double);
double f(double);
int main(void)
{
	double x1=1,x2=2;
	do{
	   double middle=x2;
		x2=x2-f(x2)*(x2-x1)/(f(x2)-f(x1));
		x1=middle;
	}while(absolute(x1-x2)>eps);
	printf("Result : %f",x2);
	return 0;
}
double absolute(double x){
	return x>0?x:(-x);
}

double f(double x)
{
	return ((x-1)*x*x-1);
}

