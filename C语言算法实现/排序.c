#include<stdio.h>

	int main(void)
{
		int i, j, a[10], t;
		printf("Enter 10 numbers to be sorted: ");
		for (i = 0; i < 10; i++)
			scanf("%d",&a[i]);
		
		for (i = 0; i < 10; i++)
		{
			for (j = 9; j > i; j--)
			{
				if (a[i] > a[j])
				{
					t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
			}
		}
		printf("\nIn sorted order: ");
		for (j = 0; j < 10; j++)
			printf("%d ", a[j]);
		return 0;
	}
