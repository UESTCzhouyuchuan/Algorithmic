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
	}                 //�������У�Ϊɶ�� 
	return re;
}

//���ص�ַ���ܷ����Զ�������main����֮��ľֲ��������ĵ�ַ 
//���Է����ⲿ������̬�������޵ı���		
		
		
		
		
		
		
		
		
