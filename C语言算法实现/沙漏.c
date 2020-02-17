#include<stdio.h>
#include<stdlib.h>

void printxing(int num,char ch);

int main(void){
	int number=0;
	char gesture;
	scanf(" %d %c",&number,&gesture);
	printxing(number,gesture);
	return 0;
}

void printxing(int num,char ch){
	if(num<7){
		printf("%c\n%d",ch,num-1);
		return;
	}
	int counter=1;
	int i,j,k;
	for(i=3;;i+=2){
		counter+=i*2;
		if((num-counter)<(i+2))
		break;
	}
	for(k=i;k>0;k-=2){
		for(j=i-k;j>0;j-=2)
		printf(" ");
		for(j=k;j>0;j--)
		printf("%c",ch);
		printf("\n");
	}
	for(k=3;k<=i;k+=2){
		for(j=i-k;j>0;j-=2)
		printf(" ");
		for(j=k;j>0;j--)
		printf("%c",ch);
		printf("\n");
	}
	printf("%d",num-counter);
	
}
