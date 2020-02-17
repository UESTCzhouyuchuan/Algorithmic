#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXNUM 10 
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode*next;
}LinkNode;
 void CreatListF(LinkNode*L,ElemType *a,int n);
 void CreatListB(LinkNode*L,ElemType *a,int n);
 void InitList(LinkNode*L);
 void DestroyList(LinkNode*L);
 void Insert(LinkNode*L,int i,ElemType e);
 void DispList(LinkNode*L);
 int  ListLenght(LinkNode*L);
 bool ListEmpty(LinkNode*L);
 bool GetElem(LinkNode*L,int i,ElemType e);
 int LocateList(LinkNode*L,ElemType e);
 bool DeleteList(LinkNode*L,ElemType e);
 void ListSort(LinkNode*L);//排序
 void ListReverse(LinkNode*L);//反转
int main(void){
	LinkNode*L=(LinkNode*)malloc(sizeof(LinkNode));
	int num[MAXNUM]={1,3,4,2,5,6,7,8,9,9,};
	int i,number;
	InitList(L);
	CreatListB (L,num,MAXNUM);
	DispList(L);
	Insert(L,9,10);
	printf("The lenght of this list is %d\n",ListLenght(L));
	DispList(L);
	printf("%d is %dth in list\n",10,LocateList(L,10));
	DeleteList(L,10);
	DispList(L);
	return 0; 
}
 void InitList(LinkNode*L)
 {
 	L->next=NULL;
 }
// void CreatListF(LinkNode*L,ElemType *a,int n) 无表头的链表不能前插，因为开端的地址无法被改变 
// {
// 	LinkNode*tempt;
// 	L->data=a[0];
// 	int i;
// 	for (i =1; i<n; i++)
// 	{
// 		tempt=(LinkNode*)malloc(sizeof(LinkNode));
// 		tempt->next=L;
// 		tempt->data=a[i];
// 		L=tempt;
// 	}
// }
 void CreatListB(LinkNode*L,ElemType *a,int n)
 {
 	LinkNode*tempt, *l=L;
 	l->data=a[0];
 	int i;
 	for (i =1; i<n; i++)
 	{
 		tempt=(LinkNode*)malloc(sizeof(LinkNode));
 		tempt->next=NULL;
 		tempt->data=a[i];
 		l->next=tempt;
 		l=tempt;
 	}
 } 
 
 void DestroyList(LinkNode*L){
 	LinkNode*per=L,*p=L->next;
 	for(; !per; ){
 		free(per);
 		per=p;
 		p=per->next;
 	}
 	
 }
 void Insert(LinkNode*L,int i,ElemType e){
 	//放到第i个位置 
 	if(i>ListLenght(L)){
 		printf("List hasn't so many component\n");
 		return ;
 	}
 	if(i<=0){
 		printf("Illeagal!\n");
 		return ;
 	}
 	if(i==1){
 		printf("表头无法改变\n");
 		return ;
 	}
	LinkNode*temp=(LinkNode*)malloc(sizeof(LinkNode));
 	temp->data=e;
 	int counter;
 	LinkNode*pL=L;
 	for(counter= 0; counter<i-2; counter++)
 	pL=pL->next;
 	temp->next=pL->next;
 	pL->next=temp;
 }
 void DispList(LinkNode*L){
 	LinkNode*pL=L;
 	for(;pL;)
 	{
 		printf("%d ",pL->data);
 		if(!pL)
 		break;
 		pL=pL->next;
 	}
 	printf("\n");
 }
 int  ListLenght(LinkNode*L)
 {
 	int counter=0;
 	LinkNode*pL=L;
 	for(;pL;pL=pL->next)
 	counter++;
 	return (counter);
 }
 bool ListEmpty(LinkNode*L)
 {
 	return (L->next?(false):(true));
 }
 bool GetElem(LinkNode*L,int i,ElemType e)
 {
 	if(i<=0&&i>ListLenght(L))
 	{
 		printf("Illegal\n");
 		return false;
 	}
 	LinkNode*pL=L;
 	int counter;
 	for (counter= 0; counter<i-1;counter++)
 	pL=pL->next;
 	pL->data=e;
 	return true;
 }
 int LocateList(LinkNode*L,ElemType e)
 {
 	int location;
 	LinkNode*pL=L;
 	for (location= 0;; location++){
 		if(pL->data==e){
 			return (location+1);
 		}
 		if(!pL)
 		break;
 		pL=pL->next;
 	}
 }
 bool DeleteList ( LinkNode*L, ElemType e)//是否所有的data==e都要被删除 ，我在这选择是 
 {
 	LinkNode*pL=L;
 	int  times=0;
 	if (pL->data==e)
 	{
 		printf ("First element equal %d but can't be deleted\n",e);						//free (L);无表头的链表不能free第一个节点，否则会产生一个无起点的链表，
																						//该链表将无法使用，也不能进行任何操作 
 	}
 	for(;pL->next;)
 	{
 		if (pL->next->data==e)
 		{
 			LinkNode*temp= pL->next; //储存要删除的节点 
 			pL->next= temp->next;
 			free (temp);
 			times++;
 		}
 		pL= pL->next;
 	}
 	if(times==0)
 	return false;
 	else
 	return true;
 }
 void ListSort(LinkNode*L)//排序需要表头 
 {
 	
 }
 void ListReverse(LinkNode*L)//反转必须有表头！ 
 {
 	
 }

