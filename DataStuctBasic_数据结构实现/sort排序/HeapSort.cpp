#include <bits/stdc++.h>
using namespace std;
#include "mysort.h"
using namespace std; 
void sift(RecType R[],int low,int high)
{
	int i=low,j=2*i;
	RecType temp=R[i];
	while (j<=high)
	{
		if (j<high&&R[j].key<R[j+1].key)
			j++;
		if (temp.key<R[j].key)
		{
			R[i]=R[j];
			i=j;
			j*=2;
		}
		else break;
	}
	R[i]=temp;
}
//template <class T> void swap(T&a,T&b)
//{
//	T c(a);a=b;b=c;
//}swap()º¯Êý´úÂë 
void HeapSort(RecType R[],int n)//¶ÑÅÅÐò
{
	
	int i;
	for (i=n/2;i>=1;i--)
		sift(R,i,n);
	for (i=n;i>=2;i--)
	{
		swap(R[1],R[i]);
		sift(R,1,i-1);
	}
} 
