//����������ܱ���2��3��5֮�����������
//ָ��������2,3,5������������������  �жϷ��������ȳ�2��ֱ����������Ϊֹ��Ȼ���5����������Ϊֹ��Ȼ���3ֱ����������Ϊֹ�������ж�ʣ��������Ƿ�Ϊ1�������1��Ϊ�����������ǳ�����
//���ɳ���: 2,3,5 ��һ����2��3��5���⣩������ 

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int coeff[3] = {2,3,5};
int main(void)
{
	priority_queue< LL, vector<LL>, greater<LL> > pq;
	set<LL>s;
	pq.push(1);	s.insert(1);
	int i,j;
	for (i=1;;i++)
	{
		LL x=pq.top();pq.pop();
		if (i==1500)
		{
			printf("%d",x);
			break;
		}
		for (j=0;j<3;j++)
		{
			LL x2=x*coeff[j];
			if (s.count(x2)==0)
			{
				s.insert(x2); pq.push(x2);
			}
		}
	}
	return 0;
}
 
