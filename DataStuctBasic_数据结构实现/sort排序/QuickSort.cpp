#include "mysort.h"
using namespace std;

int partition(RecType R[],int l,int r)
{
	int i=l,j=r-1;
	RecType tmp=R[i];
	while(i<j)
	{
		while (i<j&&R[j].key>=tmp.key)
		j--;
		R[i]=R[j];
		while (i<j&&R[i].key<=tmp.key)
		i++;
		R[j]=R[i];
	}
	R[i]=tmp;
	return i;
}
void QuickSort(RecType R[],int l,int r)
{
	int i;
	if (l<r-1)
	{
		i=partition(R,l,r);
		QuickSort(R,l,i);
		QuickSort(R,i+1,r);
	}
}
//void QuickSort(RecType R[],int l,int r)
//{
//	int i;
//	while (l<r-1)           whileÊÇ´íµÄ 
//	{
//		i=partition(R,l,r);
//		QuickSort(R,l,i);
//		QuickSort(R,i+1,r);
//	}
//}
//int partition(RecType R[],int l,int r)
//{
//	int i=l,j=r-1;
//	RecType tmp=R[i];
//	while (i<j)
//	{
//		while (i<j&&R[j].key>=tmp.key)
//		j--;
//		R[i]=R[j];
//		while (i<j&&R[i].key<=tmp.key)
//		i++;
//		R[j]=R[i];
//	}
//	R[i]=tmp;
//	return i;
//}
