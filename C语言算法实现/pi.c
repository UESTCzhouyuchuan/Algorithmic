#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double seek_pi(double);
//Çó¦Ð2017.12.16 
int main(void)
{
	double n;
	printf("Enter the times you want to multiply: ");
	scanf(" %lf",&n);
	printf("\n");
	printf("Pi equal to more or less : %.8f",2*seek_pi(n));
	system("color 3");
	system("pause");
	return 0;
}

double seek_pi(double n){
	return n==0? 1: ((pow(2*n,2)/(4*pow(n,2)-1))*seek_pi(n-1));
}


