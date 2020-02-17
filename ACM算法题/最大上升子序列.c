#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define M 200001
int num[M];
int d[M];
typedef struct node {
	int index;
	struct node*next;
}Stack;
Stack *P;
int n;
int main(void)
{
	Stack*p,*q;
	scanf("%d",&n);
	int i,j,k,t;
	for(i=0;i<n;i++)
	scanf("%d",num+i);
	P=(Stack*)malloc(sizeof(Stack));
	q=(Stack*)malloc(sizeof(Stack));
	P->next=q;
	q->index=0;
	q->next=NULL;
	d[0]=1;
	
	for (i=1;i<n;i++)
	{
		p=P->next;
		while (p!=NULL)
		{
			if (num[p->index] < num[i])
			{
				d[i]=d[p->index]+1;
				break;
			}
			p=p->next;
		}
		if (p==NULL)
		d[i]=1;
		
		p=P;
		q=(Stack*)malloc(sizeof(Stack));
		q->index=i;
		while (p->next!=NULL){
			if (d[p->next->index] <= d[i])
			{
				q->next=p->next;
				p->next=q;
				break;
			}
			p=p->next;
		}
		if (p->next==NULL)
		{
			p->next=q;
			q->next=NULL;
		}	
	}
	
	printf("%d",d[P->next->index]);
	free(P);
	return 0;
	
}

