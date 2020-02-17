#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool is_primer(int num);
int main(void){
  int maxnum=0;
  scanf(" %d",&maxnum);
  if(maxnum<=2)
  {
  	printf("%d",0);
  	return 0;
  }
  int counter=0;
  int i,j;
  for(i=3;i<=maxnum;i+=2)
  if(is_primer(i)&&is_primer(i-2))
  counter++;
  printf("%d",counter);
  return 0;
}
bool is_primer(int num){
	if(num==1)
	return false;
  int i=2;
  for(;i*i<=num;i++)
  if(!(num%i))
  return false;
  return true;
}
