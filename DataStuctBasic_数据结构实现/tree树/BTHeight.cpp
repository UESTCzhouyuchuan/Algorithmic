#include "mytree.h"

int BTHeight(BTNode *b)
{
	int l,r;
	if (b==NULL) return 0;
	else
	{
		l=BTHeight(b->lchild);
		r=BTHeight(b->rchild);
		return l>r?(l+1):(r+1);
	}
}
