#include<stdio.h>

//int fac(int m);
//int main(void){
//	int n,i;
//	scanf(" %d",&n);
//	for(i= 0; i<n; i++)
//	if(!(fac(i)%3))
//	printf("%d: %dYES\n",i,fac(i));
//	else
//	printf("%d NO\n",i);
//	
//	return 0;
//	
//}
//int fac(int m){
//	if(m==0)
//	return 7;
//	if(m==1)
//	return 11;
//	return (fac(m-1)+fac(m-2));
//}
int main(void){
	int n;
	while(scanf("%d",&n)==1){
		if(!((n+2)%4))
		printf("yes\n");
		else
		printf("no\n");
	}
	return 0;
}
