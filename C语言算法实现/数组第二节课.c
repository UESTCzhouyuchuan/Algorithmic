#include<stdio.h>
#define N 100

int main(void)
{
	int a[N]={},i,sum =0,*p=a;
	for(i =0; i< N;i++)
	sum += p[i];          //p[i]��*(p+i), 
	printf("Sum: %d",sum);
	return 0;
}

void duoweishuzu(void)
{
	
}

//�������������ݸ�����ʱ�����Ǳ���Ϊָ��

//int *a;*a=0 wrong
//&a[0][0]�ȼ���a[0] &a[3][0]�ȼ���a[3]
//&m[i][0]��ͬ��&*((m[i]+0)) m[i]