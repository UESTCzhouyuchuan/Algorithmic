#include<stdio.h>
#define N 10

int main(void)
{
	int i;
	int num[10]={1,2,5,7,8,9,5,3,4,10};
	int num1[10]={0};
	for(i=0; i<N; i++){	
	  int low=0,high=9;
	  int temp=num[i];
	   for(;low!=high;)
	   {   
	          while((num[high]>temp)&&(high>low))
				     high--;
				 if(low < high){
				 low++;
				 }
				 while((num[low]<temp)&&(low<high))
				     low++;
				     if(low<high){
					high--;
				     }
	             
	   }
	   num1[high]=temp;
	}
	for(i=0;i<N;i++)
	printf("num[%d]=%d\n",i,num1[i]);
	return 0;
}

