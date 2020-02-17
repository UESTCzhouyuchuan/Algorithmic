#include<stdio.h>
#define DEV 0.01
float jie(int n);
float shuangjie(int n,int m);
int main(void){
  float pi,middle=1/3.0;
  int n=1;
  float sum=1+middle;
  for(;middle>DEV;){
  	n++;
  	middle=jie(n/2)/shuangjie(n,n);
    sum+=middle;
  }
  printf("%f\n",2*sum);
  return 0;
}

float jie(int n){
  return n==0?1:((2*n)*jie(n-1));
}
float shuangjie(int n,int m){
	return ((2*n+1) <= m ? 1:((2*n+1)*shuangjie(n-1,m)));
}



