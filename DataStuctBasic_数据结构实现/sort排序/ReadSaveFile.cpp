#include "mysort.h"
using namespace std;
void ReadFile(FILE*fp,RecType R[],int *n)
{
	int num;
	int i=0;
	while (fscanf(fp,"%d",&num)!=EOF)
	{
		R[i++].key=num;
	}
	*n=i;
}
void SaveFile(FILE*fp,RecType R[],int n)
{
	int i;
	for (i=0;i<n;i++)
	fprintf(fp,"%d ",R[i].key);
}
