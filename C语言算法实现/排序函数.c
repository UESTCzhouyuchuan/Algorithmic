#include<stdio.h>

void max(int [],int*max,int*top);

int main(void)
{
	int n[10];
	int i,top=9,largest,secondlargest;
	printf("Enter 10 integers: \n");
	for(i=0;i<=top;i++)
	{
		scanf(" %d",&n[i]);
	}
	for(;top>=0;){
		max(n,&largest,&top);
	printf("%d,",largest);
	}
	
	return 0; 
} 
//first
void max(int n[],int*max,int*top)
{
	int i,j,tempt;
	for(i=0;i<=*top;i++)
	{
		if(n[i]>n[*top])
		{
			tempt=n[i];
			n[i]=n[*top];
			n[*top]=tempt;
		}
	}
	*max=n[*top];
	//*top=*top-1;
	//*top--;
}
//second
void selecion_sort(int a[],int length){
	int max = a[0];
	int i,max_index=0,temp;
	if(length==1)
	return;
		for(i = 0;i<length;i++)
		if(max<a[i]){
			max=a[i];
			max_index=i;
		} 
		temp=a[length-1];
		a[length-1]=max;
		a[max_index]=temp;
		selecion_sort(a,length-1);
}
//third
void bubble_int(int a[],int lenght){
	int i,j;
	int temp;//for swapping date
	for(i=0;i<lenght-1;i++)
	{
		for(j = 0;j<lenght-1-i; j++){
			if(a[j]>a[j+1]){
				temp = a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
}
