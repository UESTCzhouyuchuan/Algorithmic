#include "BTree.h"

void printBTree(BTreeNode *p){
    if (p != NULL){
        if (p->liftSon!=NULL || p->rightSon){
            printf("(");
            printf("%d",p->value);
            if(p->liftSon != NULL){
                printBTree(p->liftSon);
            }
            printf(",");
            printBTree(p->rightSon);
            printf(")");
        }
    }
}
