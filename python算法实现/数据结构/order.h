#ifndef ORDER
#define ORDER
#include "BTree.h"
void preOrder(BTreeNode *p);
void inOrder(BTreeNode *p);
void postOrder(BTreeNode *p);
//ǰ�����
void preOrder(BTreeNode *p)
{
    if (p != NULL)
    {
        printf("%d,", p->value);
        preOrder(p->liftSon);
        preOrder(p->rightSon);
    }
}
//�������
void inOrder(BTreeNode* p){
    if (p!=NULL){
        inOrder(p->liftSon);
        printf("%d,",p->value);
        inOrder(p->rightSon);
    }
}
//�������
void postOrder(BTreeNode*p){
    if (p!=NULL){
        postOrder(p->liftSon);
        postOrder(p->rightSon);
        printf("%d,",p->value);
    }
}
#endif