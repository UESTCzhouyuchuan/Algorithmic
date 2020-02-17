#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ElemType int   //或者typedef 
#define MaxSize 50
typedef struct {
	ElemType data[MaxSize];
	int length;
}SqList;
void CreatList(SqList * L, ElemType a[],int n);
void InitList(SqList * L);
void DestroyList(SqList *L);
bool ListEmpty(SqList * L);
int ListLenght(SqList * L);
void DispList(SqList * L);
bool GetElem(SqList * L,int i,ElemType  e);
int LocateElem(SqList * L,ElemType e);
bool ListInsert(SqList * L,int i,ElemType e);
bool ListDelete(SqList * L,int i,ElemType e);

int main(void){
	ElemType a[MaxSize]={0};
	SqList*L=(SqList*)malloc(sizeof(SqList));
	InitList(L);
	CreatList(L,a,MaxSize-1);
	printf("L %s empty\n",ListEmpty(L)?"is":"isn't");
	printf("L's length is %d\n",ListLenght(L));
	DispList(L);
	ElemType e;
	if(GetElem(L,9,e))
	printf("Successful\n");
	else printf("Error\n");
	DispList(L);
	printf("Location of %d in L is %d\n",29,LocateElem(L,29));
	if(ListInsert(L,9,29))
	printf("Successful\n");
	else printf("Error\n");
	DispList(L);
	if(ListDelete(L,9,29))
	printf("Successful\n");
	else printf("Error\n");
	DispList(L);
	DestroyList(L);
	return 0;
}
void CreatList(SqList * L, ElemType a[],int n){
	int i=0,k=0;
	
	while(i<n){
		L->data[k]=a[i];
		k++;i++;
	}
	L->length=n;
}
void InitList(SqList * L){
	L=(SqList*)malloc(sizeof(SqList));
	L->length=0;
}
void DestroyList(SqList * L){
	free(L);
}
bool ListEmpty(SqList * L){
	return (L->length?false:true);

}
int ListLenght(SqList * L){
	return (L->length);
}
void DispList(SqList * L){
	int i;
	for(i=0;i<L->length;i++)
	printf("%d ",L->data[i]);
	printf("\n");
}
bool GetElem(SqList * L,int i,ElemType  e){
	if(i<1||i>L->length)
	return false;
	e=L->data[i-1];
	return true;
}
int LocateElem(SqList * L,ElemType e){
	int i=0;
	for(;i<L->length;i++)
	if(e==L->data[i])
	return (i+1);
	return 0;
}
bool ListInsert(SqList * L,int i,ElemType e){
	if(i<1||i>L->length||L->length>=MaxSize)
	return false;
	int counter;//计数器
	for(counter=L->length;counter>i-1;counter--)
	L->data[counter]=L->data[counter-1];
	L->data[i-1]=e;
	L->length++;
	return true;
}
bool ListDelete(SqList * L,int i,ElemType e){
	if(i<1||i>L->length)
	return false;
	int counter;
	for(counter=i-1;counter<L->length-1;counter++)
	L->data[counter]=L->data[counter+1];
	L->length--;
	return true;
}
