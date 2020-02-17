//规范连分数
#include <bits/stdc++.h>
using namespace std;

void StandardFraction(long a,long b, int counter);
long f(long a,long b);
int main(void)
{
	int m;
	scanf ("%d",&m);
	float n;
	char ch[20];
	while (m--)
	{
		scanf("%s",ch);
		int i=0;
		bool flag=false;
		long a=1,b=0,zheng=0;
		for (i=0;ch[i]!='\0';i++)
		{
			if (flag)
			{
				b*=10;
				a*=10; 
				b+=ch[i]-'0';
				
			}
			if (ch[i]=='.')flag=true;
			if (!flag){
				zheng*=10;
				zheng+=ch[i]-'0';
			}
		}
		printf("[%d;",zheng);
		if (flag==false)
		{
			printf("]\n");
			continue;
		}
		long common=f(a,b);
		a=a/common;b=b/common;
		StandardFraction(a,b,1);
	}
	return 0;
}
long f(long a,long b)
{
	if (b==0)
	return a;
	return f(b,a%b);
}
void StandardFraction(long a,long b, int counter){
		printf("%ld",a/b);
		if (b==1||a%b==0||counter==5)
		{
			printf("]\n");
		}
		else
		{
			printf(","); 
			StandardFraction(b,a%b,counter+1);
		}

}
