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
int SeqSearch(RecType R[],int n,KeyType k);//˳����� 
int SeqSearch1(RecType R[],int n,KeyType k);//ĩβ�ӹؼ���k
int BinSearch(RecType R[],int n,KeyType k);//�۰���� 
int IdxSearch(IdxType I[],int b,RecType R[],int n,KeyType k);	//���ҷֿ� n��Ԫ�� ��b�� 
int main(void){
	return 0;
}
int SeqSearch(RecType R[],int n,KeyType k)//˳����� 
{
	int i=0;
	while (i < n && R[i].key!=k)//�ӱ�ͷ������
	i++;
	if (i>=n) //δ�ҵ�����0
	return 0;
	else
	return i+1;//�����߼�����i+1 
}
int SeqSearch1(RecType R[],int n,KeyType k)//ĩβ��ӹؼ���k 
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
int BinSearch(RecType R[],int n,KeyType k)//�۰����  ��С�������� 
{
	int low=0,high=n-1,mid;			
	while (low<=high)				//��ǰ�������Ԫ��ʱѭ�� 
	{
		mid=(low+high)/2; 
		if (R[mid].key==k)			//���ҳɹ�ʱ�����߼����� 
		return mid+1;
		if (R[mid].key>k)		//������low -mid-1�в���
		high=mid-1;
		else					//R[mid].key<k
		low=mid+1;             //������mid+1-high�����ϲ��� 
	}
	return 0;					//����ʧ�ܷ���0 
 } 
int IdxSearch(IdxType I[],int b,RecType R[],int n,KeyType k) //�ֿ���� 
{
	int s=(n+b-1)/b;// sΪÿ�����Ԫ�ظ�����ӦΪ[n/b]
	int low=0,high=b-1,mid,i;
	while (low<=high)		//���������н����۰���ң��ҵ���λ��Ϊhigh+1 
	{
		mid=(low+high)/2;
		if (I[mid].key>=k)
		high=mid-1;
		else
		low=mid+1;
	 }
	 //Ӧ�����������high+1���в��ң����������ݱ��н���˳����� 
	 i=I[high+1].link;
	 while (i<=I[high+1].link+s-1&&R[i].key!=k)
	 i++;
	 if (i<=I[high+1].link+s-1)
	 return i+1;//���ҳɹ��������߼����� 
	 else
	 return 0;//����ʧ��
	  
}

