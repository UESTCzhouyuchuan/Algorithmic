#include<stdio.h>

int main(void){
	
	double a=1.0,b;
	int i;
	printf("\n** double �͵��������ֵ**\n");
	for(i=1;i<1025;i++){
		printf("%8d%32.15e\n",i,a);
		a+=a;
		b=a+1;
		if(b-a==1)
		a=b;
	}
	
	return 0;
}
