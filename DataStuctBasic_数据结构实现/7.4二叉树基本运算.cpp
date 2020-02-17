#include <bits/stdc++.h>
using namespace std;
#define ElemType int
typedef struct Node{
	ElemType data;
	struct Node *lchild;
	struct Node *rchild;
}BTNode;
void DestroyBTree(BTNode *b);
int BTHeight(BTNode*b);
void DispBTree(BTNode*b); 
int main(void)
{
	
	return 0;
}

void DestroyBTree(BTNode *b){
	if(b==NULL)return;
	if (b->rchild!=NULL)DestroyBTree(b->rchild);
	if (b->lchild!=NULL)DestroyBTree(b->lchild);
	delete b;
}
int BTHeight(BTNode*b){
	int lh,rh;
	if (b==NULL)return 0;
	lh=BTHeight(b->lchild);
	rh=BTHeight(b->rchild);
	return ((lh>rh)?(lh+1):(rh+1));
		
}
void DispBTree(BTNode*b)
{
	if (b==NULL)return ;
	printf("%c",b->data);
	if (b->lchild!=NULL||b->rchild!=NULL)
	{
		printf("(");
		DispBTree(b->lchild);
		if (b->rchild!=NULL)
		{
			printf(",");
			DispBTree(b->rchild);
		}
		printf(")");
	}
}
