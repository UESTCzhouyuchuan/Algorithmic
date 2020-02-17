#include <bits/stdc++.h>
#define N 30
using namespace std;
typedef struct{
	char name[N];
	int price;
}good;
typedef struct node{
	good data;
	struct node*next;
}Good;
Good*front=new Good;
Good *rear=new Good;

void delete_(char*ch);
void insert(char *ch,int yuan);
void reduce(char*ch,int yuan);
void search(int tag);
int main(void)
{
	front->next=NULL;
	rear->next=NULL;
	int counter,type;
	int tag;
	char ch[N];int yuan;
	scanf ("%d",&counter);
	while (counter--)
	{
		scanf ("%d",&type);
		switch (type){
			case 1:scanf("%s %d",ch,&yuan);insert(ch,yuan);break;
			case 2:scanf("%s",ch);delete_(ch);break;
			case 3:scanf("%s %d",ch,&yuan);reduce(ch,yuan);break;
			case 4:scanf("%d",&tag);search(tag);break;
			default:break;
		}
	}
	return 0;
}
void delete_(char*ch){
	Good*p=front,*q;
	while (p->next!=NULL)
	{
		if (strcmp(ch,p->next->data.name)==0)
		{
			if (p->next->next==NULL)
			rear->next=p;
			q=p->next;
			p->next=p->next->next;
			delete q;
			break;
		}
		p=p->next;
	}
}
void insert(char *ch,int yuan){
	Good*p=front;
	Good*q=new Good;
	strcpy(q->data.name,ch);
	q->data.price=yuan;
	while (p->next!=NULL&&p->next->data.price<yuan)
	p=p->next;
	if(p->next==NULL)
	rear->next=q;
	q->next=p->next;
	p->next=q;
}
void reduce(char*ch,int yuan){
	Good*p=front,*q;
	while (p->next!=NULL)
	{
		if (strcmp(ch,p->next->data.name)==0)
		{
			p->next->data.price=yuan;
			break;
		}
		p=p->next;
	}
	q=p->next;
	if (p->next->next==NULL)
	rear->next=p;
	p->next=p->next->next;
	insert(q->data.name,q->data.price);
	delete q;
}
void search(int tag){
	switch(tag){
		case 1:printf("%s\n",front->next->data.name);break;
		case 2:printf("%s\n",rear->next->data.name);break;
	}
}
