//ɾ�������ڶ����� 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 64
typedef struct {
	int data[N];
	int rear;
	int front;
};

int main(void)
{
	int i, n, front, rear, q[2*N];
	scanf ("%d", &n);
	for (i=0;i<n;i++)
	q[i]=i+1;
	front=0;
	rear=n;
	while (rear-front>0)
	{
		printf ("%d ",q[front]);
		front++;
		q[rear++]=q[front++];
	}
	return 0;
}
//ѭ������
front=(front+1) %N;
rear=(rear+1) %N; 
 if (rear-front>0)
 num=rear-front;
 elseif(rear-front<0)
 num=N+rear-front;
 else
 num=0;
 //c++��STL include <queue>
 
 #include <cstdio>
 #include <queue>//����#include <bits/stdc++.h> 
 
 using namespace std;
 int main (void)
 {
 	queue<int> q;
 	int i,n;
 	scanf ("%d",&n);
 	for (i=0;i<n;i++)
 	q.push(i+1);
 	while (!q.empty())
 	{
 		printf ("%d", q.front());  //q.back();
 		q.pop;
 		q.push(q.front());
 		q.pop();
 	}
 	return ;
 } 
//���ȶ���(priority_queue)<stl>
��ͷ��q.top(); 
�Զ������ȼ���
#include <bits/stdc++.h>
using namespace std;
struct cmp {
	bool operator() (const int a, const int b)const {
	return a%10>b%10;
	}
}; 

int main(void)
{
	int k;
	priority_qeueu<int , vector<int>, cmp> pq;
	for ()....
}
//������ ����ķ����Խṹ һ���ڵ��������������
 typedef struct node{
 	ElemType data;
 	struct node*fathor;
 	struct node*leftson;
 	struct node*rightson;
 }; 
 // �������ı���
  ��1��ǰ��������ȷ��ʸ����ڷ����������� ���ǰ�����������
  ��2����������� 
  ��3����������� 
//��������Ӧ�ã��� ��ȫ������
 
bool mycompare(int a,int b)
{
	return a>b;
}





















