//#include <bits/stdc++.h>//优先队列举例 
//using namespace std;
//typedef int ElemType;
//typedef struct{
//	ElemType data;
//	int x;
//}Queue_stack;
//struct mycom
//{
//	bool operator()(const Queue_stack e1,const Queue_stack e2)const{
//		return e1.x < e2.x;
//	}
//};
//int main(void)
//{
//	priority_queue<Queue_stack,vector<Queue_stack>,mycom> p;
//	int i;
//	Queue_stack q;
//	for (i=0;i<5;i++){
//		q.data=i;
//		q.x=i+1;	
//		p.push(q);
//	}
//	for (i=0;i<5;i++){
//	printf("%d ",p.top().data);
//	p.pop();
//}
//
//	return 0; 
//}

#include <bits/stdc++.h>
using namespace std;
void baoshu(int n);
int main(void)
{
	int n;
	while (scanf ("%d",&n)==1)
	{
		baoshu(n);
	}
	return 0;
}

void baoshu(int n)
{
	queue <int> p;
	int i=1;
	for (i=1;i<=n;i++)
	p.push(i);
	while(!p.empty())
	{
		printf("%d ",p.front());
		p.pop();
		p.push(p.front());
		p.pop();
	}
	
}





