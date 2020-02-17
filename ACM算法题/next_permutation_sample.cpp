//C++ÖÐSTLº¯Êýnext_permutation(first*,last*,mycompare);
#include <bits/stdc++.h>
using namespace std;
#define N 10

int main(void)
{
	int a[N];
	int i,n;
	while (scanf ("%d",&n)==1)
	{
		for (i=0;i<n;i++)
		scanf ("%d",&a[i]);
		sort(a,a+n);
		do{
			for (i=0;i<n;i++)
			printf("%d ",a[i]);
			printf("\n");
		}while (next_permutation(a,a+n));
		printf("\n");
	}
	return 0;
 } 
