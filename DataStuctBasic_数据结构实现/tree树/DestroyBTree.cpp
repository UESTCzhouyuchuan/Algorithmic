#include "mytree.h"

void DestroyBTree(BTNode* &b)
{
	if (b!=NULL)
	{
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		delete b;
	}
}
