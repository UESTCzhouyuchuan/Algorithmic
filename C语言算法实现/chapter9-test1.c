#include<stdio.h>


double harmonic_mean(double a,double b)
{
	return (2*a*b)/(a+b)*1.0f;
}
int main()
{
	float x,y;
	printf("Please input two double numbers: \n");
	scanf("%f %f",&x,&y);
	printf("The harmonic mean of %g and %g is: %g",x,y,harmonic_mean(x,y));
	return 0;
}

