#include <bits/stdc++.h>
#include"mytree.h"
using namespace std;


int main(void)
{
	char str[100]="A(B(F,G(H,I)),C(D(J,K),E))";
	BTNode *b;
	CreateBTree(b,str);
	AllPath(b);
	DispBTree(b);
	DestroyBTree(b);
	return 0;
 } 
