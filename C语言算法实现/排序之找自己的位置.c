#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 50
#define ElemType int 
typedef struct {
	ElemType data[MAXNUM];
	int length;
}SqList;
void FileIn (SqList*L);
void Position(SqList *L);
void DispList(SqList *L);
void DestroyList(SqList *L);
int PartPosition(SqList L, ElemType temp);
int main(void)
{
	SqList*L=(SqList*)malloc(sizeof(SqList));
	FileIn(L);
	Position(L);	
	DispList(L);
	DestroyList(L);
	return 0;
}
void FileIn(SqList*L)
{
	FILE*fp;
	int i;
	if((fp=fopen("in.txt","r+"))==NULL)
	{
		perror("Error!");
		exit(EXIT_FAILURE);
	}
	fscanf(fp,"%d ", &L->length);
	if (L->length>=MAXNUM)
	{
		printf("The numbers are too more.\n");
		exit(EXIT_FAILURE);
	}
	for ( i=0; i<L->length ;i++)
	fscanf(fp,"%d ", &L->data[i]);
	fclose(fp);
}
void Position(SqList *L)
{
	SqList q= *L;
	int t,index;
	for (t=0;t<L->length;t++)
	{
		index=PartPosition(q, q.data[t]);
		L->data[index]=q.data[t];
	}
}
int PartPosition(SqList L, ElemType temp)
{
	int i=0,j=L.length-1;
	while (i<j)
	{
		while (i<j&&L.data[j]>temp)
		j--;
		while (i<j&&L.data[i]<=temp)
		i++;
		if(i<j)
		{
			L.data[i]=L.data[i]+L.data[j];
			L.data[j]=L.data[i]-L.data[j];
			L.data[i]=L.data[i]-L.data[j];
		}
	}
	return i;
}
void DispList(SqList *L)
{
	int i;
	for (i=0;i<L->length;i++)
	printf("%d ",L->data[i]);
	printf("\n");
}
void DestroyList(SqList *L)
{
	free(L);
}
