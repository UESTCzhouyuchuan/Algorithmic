//删除倒数第二个牌 
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
//循环队列
front=(front+1) %N;
rear=(rear+1) %N; 
 if (rear-front>0)
 num=rear-front;
 elseif(rear-front<0)
 num=N+rear-front;
 else
 num=0;
 //c++中STL include <queue>
 
 #include <cstdio>
 #include <queue>//或者#include <bits/stdc++.h> 
 
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
//优先队列(priority_queue)<stl>
队头用q.top(); 
自定义优先级：
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
//二叉树 特殊的非线性结构 一个节点最多有两个儿子
 typedef struct node{
 	ElemType data;
 	struct node*fathor;
 	struct node*leftson;
 	struct node*rightson;
 }; 
 // 二叉树的遍历
  （1）前序遍历：先访问根，在访问左子树， 最后按前序遍历右子树
  （2）中序遍历： 
  （3）后序遍历： 
//二叉树的应用：堆 完全二叉树
 
bool mycompare(int a,int b)
{
	return a>b;
}





















