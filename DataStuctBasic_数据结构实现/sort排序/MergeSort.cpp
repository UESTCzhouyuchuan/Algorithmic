#include <bits/stdc++.h>
#include "mysort.h"
using namespace std;

void Merge(RecType R[],int l,int mid,int r)
{
	RecType *R1;
	int i=l,j=mid+1,k=0;
	R1=new RecType[r-l];
	while (i<=mid&&j<r)
		if (R[i].key<=R[j].key)
			R1[k++].key=R[i++].key;
		else R1[k++].key=R[j++].key;
	while (i<=mid) R1[k++]=R[i++];
	while (j<r) R1[k++]=R[j++];
	for (k=0,i=l;i<r;k++,i++)
		R[i]=R1[k]; 
	delete R1;
}
void MergeSortDC(RecType R[],int l,int r)
{
	int mid;
	if (l<r-1){
		mid=(l+r-1)/2;
		MergeSortDC(R,l,mid+1);
		MergeSortDC(R,mid+1,r);
		Merge(R,l,mid,r);
	}
}
void MergeSort(RecType R[],int n)
{
	MergeSortDC(R,0,n);
 } 
