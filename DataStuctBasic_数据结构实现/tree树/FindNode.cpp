#include "mytree.h"

BTNode*FindNode(BTNode*b,ElemType e)
{
	BTNode*p;
	if (b==NULL)
	{
		return NULL; 
	}
	else if(b->data==e)
		return b;
	else
	{
		p=FindNode(b->lchild,e);
		if (p!=NULL)
		return p;
		else
		return FindNode(b->rchild,e);
	 } 
}
