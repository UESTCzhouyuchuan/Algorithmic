#include "BTree.h"
#include "order.h"
#include "printBTree.h"

using namespace std;

int main()
{
    srand((unsigned)time(NULL));
    int num[M];
    int i = 0;
    printf("ԭ������:");
    for (i = 0; i < M; i++)
    {
        num[i] = rand() % M + 1;
        printf("%d,", num[i]);
    }
    BTreeNode *root = new BTreeNode;
    if (root == NULL)
    {
        perror("Error:");
        exit(EXIT_FAILURE);
    }
    root->value = num[0];
    root->rightSon = NULL;
    root->liftSon = NULL;
    for (i = 1; i < M; i++)
    {
        BTreeNode *p = new BTreeNode;
        if (p == NULL)
        {
            perror("Error:");
            exit(EXIT_FAILURE);
        }
        p->value = num[i];
        p->rightSon = NULL;
        p->liftSon = NULL;
        insertItem(p, root);
    }
    printBTree(root);
    printf("\n�������:");
    inOrder(root);
    printf("\nǰ�����:");
    preOrder(root);
    printf("\n�������:");
    postOrder(root);
    destroyBTree(root);
    return 0;
}
void destroyBTree(BTreeNode *&p)
{
    if (p != NULL)
    {
        destroyBTree(p->rightSon);
        destroyBTree(p->rightSon);
        free(p);
    }
}