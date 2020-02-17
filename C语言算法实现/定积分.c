#include<stdio.h>


float f(float x,int n);
double absolute_number(float);
int main(void)
{
	float x1,x2,x;                               //extreme point of the region
	float sum=0,real_sum;                        //the sum indicates the definite intergral
	float n;
	double error=1.0;                     
	int m,MAX=100;                              //find  definite integral of x^m
	printf("Enter point number of the function: ");
	scanf(" %d",&m);                                                
	printf("Enter a region between x1 and x2: ");
	scanf("%f %f",&x1,&x2);                 
	real_sum=f(x2,m+1)/(m+1)-f(x1,m+1)/(m+1);   //the real area
	for(;error > (1e-5);MAX+=100)               
	{
		sum=0;
		n=(x2-x1)/MAX;                         //the number of little refions are n
	for(x=x1;x<=x2;x+=n)
	{
		sum=sum+f(x,m)*n;
	}
	error=absolute_number(real_sum-sum);
    //if(error<(1e-5))                                                  
	printf("After %dth count.\nThe area of x^%d between %g and %g is %g\n",MAX/100,m,x1,x2,sum);
	printf("The %dth error is %f\n",MAX/100,error);
	}
	return 0;
}

double absolute_number(float n)
{
	if(n>0)
	return n;
	else
	return -n;
}

float f(float x,int m)
{
	return m==0?1:x*f(x,m-1);
} 