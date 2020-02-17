#include <bits/stdc++.h>
#include "mysort.h"
using namespace std;

void Disp(RecType R[],int n)
{
	int i;
	for (i=0;i<n;i++)
	printf("%d%c",R[i].key,i==n-1?'\n':' ');
	printf("%d\n",n);
}
