#include <bits/stdc++.h>
using namespace std;
#define MAXI 100
typedef int KeyType;
typedef struct{
	KeyType key;
	int link;
}IdxType;
typedef struct{
	KeyType key;
}RecType;
int SeqSearch(RecType R[],int n,KeyType k);//顺序查找 
int SeqSearch1(RecType R[],int n,KeyType k);//末尾加关键字k
int BinSearch(RecType R[],int n,KeyType k);//折半查找 
int IdxSearch(IdxType I[],int b,RecType R[],int n,KeyType k);	//查找分块 n个元素 共b块 
int main(void){
	return 0;
}
int SeqSearch(RecType R[],int n,KeyType k)//顺序查找 
{
	int i=0;
	while (i < n && R[i].key!=k)//从表头往后找
	i++;
	if (i>=n) //未找到返回0
	return 0;
	else
	return i+1;//返回逻辑符号i+1 
}
int SeqSearch1(RecType R[],int n,KeyType k)//末尾添加关键字k 
{
	int i=0;
	R[n].key=k;
	while (R[i].key!=k)
	i++;
	if (i==n)
	return 0;
	else
	return i+1;
}
int BinSearch(RecType R[],int n,KeyType k)//折半查找  从小到大排序 
{
	int low=0,high=n-1,mid;			
	while (low<=high)				//当前区间存在元素时循环 
	{
		mid=(low+high)/2; 
		if (R[mid].key==k)			//查找成功时返回逻辑符号 
		return mid+1;
		if (R[mid].key>k)		//继续在low -mid-1中查找
		high=mid-1;
		else					//R[mid].key<k
		low=mid+1;             //继续在mid+1-high区间上查找 
	}
	return 0;					//查找失败返回0 
 } 
int IdxSearch(IdxType I[],int b,RecType R[],int n,KeyType k) //分块查找 
{
	int s=(n+b-1)/b;// s为每个块的元素个数，应为[n/b]
	int low=0,high=b-1,mid,i;
	while (low<=high)		//在索引表中进行折半查找，找到的位置为high+1 
	{
		mid=(low+high)/2;
		if (I[mid].key>=k)
		high=mid-1;
		else
		low=mid+1;
	 }
	 //应先在索引表的high+1块中查找，再在主数据表中进行顺序查找 
	 i=I[high+1].link;
	 while (i<=I[high+1].link+s-1&&R[i].key!=k)
	 i++;
	 if (i<=I[high+1].link+s-1)
	 return i+1;//查找成功，返回逻辑符号 
	 else
	 return 0;//查找失败
	  
}

