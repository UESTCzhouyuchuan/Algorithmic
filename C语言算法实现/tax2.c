#include<stdio.h>

int main()
{
	float a,b;
	printf("Enter income: \n");
	scanf("%f",&a);
	if(a>7000.00)
	{
		b=2300.00+(a-7000)*6/100.00;
		printf("The tax is: $%.2f",b);
		return 0; 
	}
	if(a>5250.00){
		b=142.50+(a-5250)*5/100.00;
		printf("The tax is: $%.2f",b);
		return 0; 
		
	}
	if(a>3750.00){
		b=82.50+(a-3750)*4/100.00;
		printf("The tax is: $%.2f",b);
		return 0; 
	}
	if(a>2250){
		b=37.50+(a-2250)*3/100.00;
		printf("The tax is: $%.2f",b);
		return 0; 
	}
	if(a>750){
		b=7.50+(a-750)*2/100.00;
		printf("The tax is: $%.2f",b);
		return 0; 
	}
	else{
		b=a/100.00;
		printf("The tax is: $%.2f",b);}
		return 0; 
	
	
}





