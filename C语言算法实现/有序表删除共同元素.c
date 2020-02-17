//一个有序链表删除共同元素
#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 50
#define ElemType int

typedef struct Node{
	ElemType data;
	struct Node*next;
}LinkNode;

void delcomm(LinkNode*L)
{
	LinkNode*p=L->next,*q;
	while (p->next!=NULL)
	{
		if (p->data==p->next->data)
		{
			q=p->next;
			p->next=p->next->next;
			free (q);
		}
		else
		{
			p=p->next; 		//连续多个相同节点可以通过这个被删除 
		} 
	}
	
} 
void main()
{
	
} 
 
