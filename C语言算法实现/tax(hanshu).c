#include<stdio.h>

float tax_(float a, float tax)
{
	
	
	if (a > 7000.00f)
	{
		tax = 2300.00f + (a - 7000.0f) * 6.0f / 100.00f;
		
	}
	else if (a > 5250.00f) {
		tax= 142.50f + (a - 5250.0f) * 5.0f / 100.00f;
		

	}
	else if (a > 3750.00f) {
		tax = 82.50f + (a - 3750.0f) * 4.0f / 100.00f;
		
	}
	else if (a > 2250.0f) {
	tax = 37.50f + (a - 2250.0f) * 3.0f / 100.00f;
		
	}
	else if (a > 750.0f) {
		tax = 7.50f + (a - 750.0f) * 2.0f / 100.00f;
		
	}
	return tax;
	
}
int main(void)
{
	float n=0;
	float tax=0;
	printf("Enter amount of taxable income: \n");
	scanf("%f",&n);
	printf("Tax due: $%.2f", tax_(n,tax));
	return 0;
}
