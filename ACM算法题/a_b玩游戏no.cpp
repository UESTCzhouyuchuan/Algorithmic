//error
/*
���ӣ�https://www.nowcoder.com/acm/contest/109/F
��Դ��ţ����
����������S��T��|S| >= |T|�� alice��bob����������S��
bob���֡� ����ÿ�β�����
alice��bob��ѡ��ɾ��S�ĵ�һλ�����һλ�� 
�������Ժ�Ĵ��ĳ��ȵ���|T|ʱ����Ϸֹͣ��
 ���ֹͣʱ�Ĵ�=T����alice��ʤ������bob��ʤ�� 
 ����alice��bob����ȡ���Ų��Ե�����£�˭Ӯ��
*/ 

#include <bits/stdc++.h>
#define N 5000
typedef struct {
	char data[N];
	int length;
}SqString;
SqString s,t;
void GetNextval (SqString t, int *nextval);
int KMPIndex (SqString s, SqString t);

int main(void)
{
	
	int nextval[N];
    int counter;
    scanf ("%d",&counter);
    int i;
    for (i=0;i<counter;i++)
    {
      scanf ("%s %s",s.data,t.data);
      s.length=strlen(s.data);
      t.length=strlen(t.data);
      if (KMPIndex(s,t)>=0)
      {
          if ((strlen(s.data)-strlen(t.data))%2==0)
          { 
              printf("Alice\n");
          }   
          else
              printf("Bob\n");
      }
        else
            printf("Bob\n");
    }
	
	return 0;
}
void GetNextval (SqString t, int *nextval)
{
	int j=0,k=-1;
	nextval[0]=-1;
	while (j<t.length)
	{
		if (k==-1||t.data[j]==t.data[k])
		{
			j++;k++;
			if (t.data[j]!=t.data[k])
			nextval[j]=k;
			else
			nextval[j]=nextval[k];
		}
		else
		k=nextval[k];
	}
}
int KMPIndex (SqString s, SqString t){
	int nextval[N],i=0,j=0;
 	GetNextval(t,nextval);
	while (i<s.length &&j<t.length)
	{
		if (j==-1||s.data[i]==t.data[j]){
			i++;j++;
		}
		else
		j=nextval[j];
	}
	if (j==t.length)
	{
		return (i-t.length);
	}
	else
	return -1;
}
