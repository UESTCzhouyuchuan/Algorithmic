#include<stdio.h>


int *find_large(int a[],int n);
int main()
{
	int i=0;
	int a[]={};
	char ch;
	printf("Enter some numbers: ");
	do{
		scanf(" %d",&a[i]);
		ch=getchar();
		i++;
	}while(ch!='\n');
	printf("Largest: %d",*find_large(a,i));
	return 0;
}

int*find_large(int a[],int n)
{
	int j;
	int*re=&a[n-1];
	for(j=0;j<n-1;j++)
	{
		if(a[j]>*re)  //if(a[j]>a[n-1])
		{             //{
			re=&a[j]; //&a[n-1]=&a[j];}
		}             //return &a[n-1];
	}                 //这样不行，为啥？ 
	return re;
}

//返回地址不能返回自动变量（main函数之外的局部变量）的地址 
//可以返回外部变量或静态储存期限的变量		
		
		
		
		
		
		
		
		
