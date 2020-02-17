#include<stdio.h>
#include<stdlib.h>


int is_prime(int n);

int main(void){
	int left_region,right_region;
	int i;
	printf("Enter the region(x,y): ");
	scanf(" (%d,%d)",&left_region,&right_region);
	printf("Prime as follows: \n");
	for(i = left_region;i<=right_region;i++){
		if(is_prime(i))
		printf("%d	",i);
	}
	return 0;
}

int is_prime(int n){
	int i;
	for(i = 2;i*i<n;i++){
		if(n%i==0)
		return 0;
	}
	return 1;
}
