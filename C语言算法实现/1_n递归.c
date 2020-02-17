#include<stdio.h>
#include<math.h>

float sum_max(float num);

int main(void)
{
	float num;
	printf("Enter the number: ");
	scanf(" %f",&num);
	printf("\n");
	printf("The total of %g times: %g",num,sum_max(num));
	return 0;
}

float sum_max(float num)
{
	return num==0 ? 0:(pow(-1,num+1)*(1/num)+sum_max(num-1));
}