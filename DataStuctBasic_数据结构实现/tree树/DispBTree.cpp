#include "mytree.h"

void DispBTree(BTNode*b)
{
	if (b!=NULL)
	{
		printf("%c",b->data);
		if (b->lchild!=NULL||b->rchild!=NULL)
		{
			printf("(");
			DispBTree(b->lchild);
			if (b->rchild!=NULL)
			printf(",");
			DispBTree(b->rchild);
			printf(")");
		}
	}
}
