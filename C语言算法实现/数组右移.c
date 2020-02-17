#include<stdio.h>
#include<stdlib.h>

void move(int a[],int member,int number);
int main(void){
  int num=0,changemove=0;
  scanf(" %d %d",&num,&changemove);
  int matric[num];
  int i=0;
  for(;i<num;i++)
  scanf(" %d",&matric[i]);
  move(matric,changemove%num,num);
  return 0;
}

void move(int a[],int member,int number){
  int i=member,counter=0,t=0,k=0;
  do{
  	if(k==i%number)
  	{
  		k++;
  		i++;
  	}
  	else{
  		t=a[k];
  	a[k]=a[i%number];
    a[i%number]=t;
	
  	}
	counter++;
    i+=member;
    
  }while(counter<number);
  for(i=0;i<number;i++)
  printf("%d ",a[i]);
   
}
