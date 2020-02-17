#include <bits/stdc++.h>
using namespace std;
int resolve(int num);
int main(void)
{
	int num;
	cin>>num;
	if (resolve(num)==num)
	printf("No solution\n");
	return 0;
}

int resolve(int num)
{
	int i;
	for (i=2;i<sqrt(num);i++)
	{
		if (num%i==0)
		break; 
	}
	
	if (i*i>=num)
	{
		
		return num;
	}
	else
	{	printf("%d*",i);
		if(resolve(num/i)==num/i)
		printf("%d",num/i);;
		return i;
	}

	
}
