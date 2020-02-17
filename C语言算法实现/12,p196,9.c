#include<stdio.h>
#define MAX 5

double inner_product(const double *a,const double *b,int n);//这样写编译器会报错，为什么 

/*double inner_product(double *a,double *b,
                      int n);*/

int main(void)
{
	double a[MAX],b[MAX];
	double *p;
	printf("Enter 5 numbers for the first array: \n");
	for(p= a; p < a+MAX;p++)
	scanf(" %lf",p);
	printf("Enter 5 numbers for the second array: \n");
	for(p = b; p < b+MAX;p++)
	scanf(" %lf",p);
	printf("The inner product: %f",inner_product(a,b,MAX));
	return 0;
}

double inner_product(const double *a,const double *b,int n) 
//double inner_product(double *a,double *b,int n)
{
	double *p1=a,*p2=b;
	double sum=0;   //count the total of them
	while(p1<a+n&&p2<b+n)
	{
		sum+=(*p1)*(*p2);
		p1++;
		p2++;
	}
	return sum;
}