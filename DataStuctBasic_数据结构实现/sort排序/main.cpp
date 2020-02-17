#include <bits/stdc++.h>
#include "mysort.h"
using namespace std;

int main(void)
{
	FILE*fp;
	if((fp=fopen("in.txt","r"))==NULL)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	RecType R[MAX];int n=0;
	ReadFile(fp,R,&n);fclose(fp);
	Disp(R,n);
	MergeSort(R,n);
	Disp(R,n);
	return 0;
} 
