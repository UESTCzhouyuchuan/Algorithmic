#include<stdio.h>

float a[10];
int n=0;
void get_data(void)
{
	char ch;
	printf("Please input less than 10 double numbers:\n");
	do{
		scanf("%f",&a[n]);
		n++;
	}while((ch=getchar())!='\n');
	return;
}
float harmonic_array(float b[],int n)
{
	int i;
	float sum=0;
	for(i=0;i<n;i++)
	sum=sum+1.0f/b[i];
	return n/sum*1.0f;
}

int main()
{
	int i,j;
	get_data();
	
	printf("The harmonic mean of this array is: %.5f",harmonic_array(a,n));
	return 0;
	
	
}