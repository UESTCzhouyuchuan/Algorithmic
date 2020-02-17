#include<stdio.h>
#include<stdlib.h>
#define N 5
void delete(int a[],int indix,int *n);
int main(void){
	int person[N]={0};
	int i,j=0,num=N,indix=0;
	for(i=0;i<N;i++){
		person[i]=i+1;
	}
		for(;num!=1;){
		if((j+1)%5==0){
			delete(person,indix,&num);
			j=0;
		}
		j++;
		indix++;
		indix=indix%(num);	
	}
    printf("最后一个人: %d\n",person[0]);
	return 0;	
}

void delete(int a[],int indix,int*n){
	int i;
	for(i = indix;i<*n-1;i++){
		a[i]=a[i+1];
	}
	*n=*n-1;
}
