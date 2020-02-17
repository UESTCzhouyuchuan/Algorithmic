#include<stdio.h>

void spilt_date(int day_of_year,int year,int *month,int *day);

int main(void)
{
	int day_of_year,year,month,day;
	printf("Enter a day.");
	scanf("%d",&day_of_year);
	spilt_date(day_of_year,year,&month,&day);
	printf("Month: %d Day: %d",month,day);
	return 0;
}

void spilt_date(int day_of_year,int year,int *month,int *day)
{
	
}
