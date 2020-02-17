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
	ListSort(L);
	DispList(L);
	ListReverse(L);
	DispList(L);
	return 0; 
}
 void InitList(LinkNode*L)
 {
 	L->next=NULL;
 }
 void CreatListF(LinkNode*L,ElemType *a,int n)
 {
 	if(n<1){
 		printf("Illegal!\n");
 		return ;
 	}
	LinkNode*tempt;
 	int i;
 	for (i =0 ; i<n; i++)
 	{
 		tempt=(LinkNode*)malloc(sizeof(LinkNode));
 		if(tempt==NULL)
		{
		printf("Apply for room failed!\n");
		return ;
		}
 		tempt->next=L->next;
 		tempt->data=a[i];
 		tempt->next=L->next;
 		L->next=tempt;
 	}
 	
 }
 void CreatListB(LinkNode*L,ElemType *a,int n)
 {
 	if(n<1){
 		printf("Illegal!\n");
 		return ;
 		}
 	
	LinkNode*l=L,*tempt;
 	int i;
 	for (i =0 ; i<n; i++)
 	{
 		tempt=(LinkNode*)malloc(sizeof(LinkNode));
 		if(tempt==NULL)
		{
		printf("Apply for room failed!\n");
		return ;
		}
 		tempt->data=a[i];
 		l->next=tempt;
 		l=tempt;
 	}
 	l->next=NULL;
 } 
 
 void DestroyList(LinkNode*L){
 	LinkNode*per=L->next,*p=per->next;
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
	LinkNode*tempt=(LinkNode*)malloc(sizeof(LinkNode));
	if(tempt==NULL)
	{
		printf("Apply for room failed!\n");
		return ;
	}
 	tempt->data=e;
 	if(i==1)
 	{
 		tempt->next=L->next;
 		L->next=tempt;
 		return ;
 	}
 	int counter;
 	LinkNode*pL=L->next;
 	for(counter= 0; counter<i-2; counter++)
 	pL=pL->next;
 	tempt->next=pL->next;
 	pL->next=tempt;
 }
 void DispList(LinkNode*L){
 	LinkNode*pL=L->next;
 	if(ListEmpty(L)){
 		printf("Empty!\n");
 		return;
 	}
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
 	LinkNode*pL=L->next;
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
	 LinkNode*pL=L->next;
 	if(pL==NULL){
 		printf("Empty!\n");
 		return false;
 		}
 	int counter;
 	for (counter= 0; counter<i-1;counter++)
 	pL=pL->next;
 	pL->data=e;
 	return true;
 }
 int LocateList(LinkNode*L,ElemType e)
 {
 	int location;
 	LinkNode*pL=L->next;
 	if(pL==NULL){
 		printf("List is empty!\n");
 		return -1;
 	}
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
 void ListSort(LinkNode*L)
 {
 	LinkNode*p,*q,*pre;
 	p=L->next->next;
 	L->next->next=NULL;
 	while(p!=NULL)
 	{
 		q=p->next;
 		pre=L;
 		while(pre->next!=NULL&&pre->next->data<p->data)
 		pre=pre->next;
 		p->next=pre->next;
 		pre->next=p;
 		p=q;
 	}
 	
 }
 void ListReverse(LinkNode*L)
 {
 	LinkNode*p=L->next,*q=p->next,*k;
 	p->next=NULL;
 	for(;q;)
 	{
 		k=q->next;
 		q->next=p;
 		p=q;
 		q=k;
 	}
 	L->next=p;
 	
 }

