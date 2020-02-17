#ifndef B_TREE
#define B_TREE
#define M 10
#include <bits/stdc++.h>

typedef struct myList
{
    int value;
    struct myList *liftSon;
    struct myList *rightSon;
} BTreeNode;

void insertItem(BTreeNode *p, BTreeNode *root);
void destroyBTree(BTreeNode *&b);

void insertItem(BTreeNode *p, BTreeNode *root)
{
    BTreeNode *q = root;
    while (true)
    {
        if (q->value <= p->value)
        {
            if (q->rightSon == NULL)
            {
                q->rightSon = p;
                break;
            }
            else
                q = q->rightSon;
        }
        else
        {
            if (q->liftSon == NULL)
            {
                q->liftSon = p;
                break;
            }
            else
                q = q->liftSon;
        }
    }
}
#endif