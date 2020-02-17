#include<stdio.h>

int main(void)
{
	int i,j,t; 
	for(i=0;i<20;i++)
	   for(j=0;j<100;j++){
	   	      t=(100-i-3*j);
	   	      if(t<0)
	   	      continue;
	   	      if((i*5+t*3+j)==100){
	     		printf("There is 100 qian and buy %d jiwong,%d muji,%d jichu\n ",i,t,3*j);
	     		
	     	}
	     }
	     
	     return 0;
}
