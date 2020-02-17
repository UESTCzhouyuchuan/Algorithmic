#include<stdio.h>
#include<stdlib.h>

int main()
{
	int b[100],i,j,t,middle;
	char ch;
	printf("Enter several numbers:");
	for (t = 0;; t++)
	{
		scanf("%d", &b[t]);
		ch = getchar();
		if (ch == '\n')
			break;
	}
	for(i=0;i<t;i++)
		for (j = t - 1; j > i; j--)
		{
			if (b[j] > b[i])
			{
				middle = b[j];
				b[j] = b[i];
				b[i] = middle;
			}
		}
	printf("After being orderde");
	for (i = 0; i < t; i++)
		printf("%4d", b[i]);
	system("pause");
	return 0;
}

