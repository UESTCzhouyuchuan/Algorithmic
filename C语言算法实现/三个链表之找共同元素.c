//������ͷ���������ҹ�ͬԪ��
#include <stdio.h>
#include <stdlib.h>
#define ElemType int
typedef struct Node{
	ElemType data;
	struct Node *next;
}LinkNode;

void CommNode (LinkNode*LA, LinkNode*LB, LinkNode *LC)
{
	LinkNode*pa=LA->next, *pb=LB->next, *pc=LC->next,*q,*r;
	LA->next=NULL;
	r=LA;
	while (pa!=NULL)
	{
		while (pb!=NULL&&pa->data<pb->data)
		pb=pb->next;
		while (pc!=NULL&&pc->data<pa->data)
		pc=pc->next;
		if(pb!=NULL&&pa!=NULL&&pa->data==pb->data
		&&pc->data==pa->data)
		{
			r->next=pa;
			r=pa;
			pa=pa->next;
		}
		else
		{
			q=pa; 				//��¼ԭ��pa�ĵ�ַ ����free 
			pa=pa->next;
			free(q); 
		}
	}
	r->next=NULL; 
} 
int main(){
	return 0;
}
