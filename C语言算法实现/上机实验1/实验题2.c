#include<stdio.h>
#include<math.h>

int jiecheng (int num);

int main(void){
	int n;
	printf("Enter n: \n");
	scanf(" %d",&n);
	printf("log2n	n^(1/2)	n	nlog2n	n^2	n^3	2^n	n!\n");
	int i;
	for(i=1;i<n+1;i++){
		printf("%.2f	%.2f%4d	%.2f	%.2g	%.2g	%.2g	%d\n",log2(i),sqrt(i),i,i*(log2(i)),pow(i,2),pow(i,3),pow(2,i),jiecheng(i));
	}
	return 0;
} 

int jiecheng(int num){
	return (num==1?1:(num*jiecheng(num-1)));
}
