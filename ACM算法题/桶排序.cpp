#include<stdio.h>
#include<string>
#define MAXNUM 1000000
int bigArray[MAXNUM];
int main(void){
	int counter,num,i,j;
	while(scanf(" %d",&counter)==1){
		memset(bigArray,0,MAXNUM);
		for(i=0;i<counter;i++){
			scanf(" %d",&num);
			bigArray[num+500000]++;
		}
		for(i=MAXNUM-1;i>0&&counter>0;i--)
		for(j=bigArray[i];j>0;j--){
			printf("%d ",i-500000);
			counter--;
		}
		
	}
	return 0;
	
}
