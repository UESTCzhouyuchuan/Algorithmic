#include<stdio.h>
#include<stdlib.h>
 
int main(void){
	int n;
	printf("Enter n: \n");
	scanf(" %d",&n);
	int sum=0;                //记录素数个数
	int*a=(int*)malloc((n+1)*sizeof(int));
	int i,j;                 //进行遍历
	for(i=0;i<n+1;i++)
	a[i]=0;                  //初始化数组a中元素全为零 
	for(i = 2 ; i < n/2+ 1;i++)
	  for(j=2;i*j<n+1;j++)
	  a[i*j]=1;
	for(i=2;i<n+1;i++)
	if(!a[i])
	sum++; 
	printf("The number of primer is %d",sum);
	return 0;
}

