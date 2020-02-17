#include<stdio.h>

int main(void){
	unsigned long num;
	int i;
	int a[10]={0,};
	printf("Enter a number: ");
	scanf(" %ld",&num);
	puts("\n");
	for(;num>0;){
		a[num%10]++;
		num/=10;
	}
	printf("Digit:		");
	for(i=0;i<10;i++){
		printf("%5d",i);
	}
	printf("\nOccurrence:	");
	for(i=0;i<10;i++){
		printf("%5d",a[i]);
	}
	return 0;
}
