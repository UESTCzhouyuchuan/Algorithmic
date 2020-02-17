#pragma once
#include <bits/stdc++.h>
#define ElemType char
#define MAXV 100

typedef struct node{
	ElemType data;
	struct node*lchild;
	struct node*rchild;
}BTNode;

/***************************
*���ŷ���ʾ������
****************************/ 
void CreateBTree(BTNode* &b,char *str);


void DestroyBTree(BTNode * &b);
BTNode* FindNode(BTNode *b,ElemType e);
int BTHeight(BTNode *b);
void DispBTree(BTNode*b);

/************************
*���ֱ�����ʽ           
************************/
void PreOrder(BTNode *b);
void PreOrder1(BTNode *b);
void PreOrder2(BTNode *b);

void InOrder(BTNode *b);
void InOrder1(BTNode *b);

void PostOrder(BTNode *b);
void PostOrder1(BTNode *b);

/*************************** 
*Ҷ�ӽ�㵽����������·��*
***************************/ 
void AllPath(BTNode*b);
void AllPath1(BTNode*b); 

/********************
*�����������򣬺��� 
*ȷ��������          
*********************/

 BTNode*CreateBTl1(char *pre,char *in,int n);
 
 BTNode*CreateBTl2(char *in,char *post,int n);
