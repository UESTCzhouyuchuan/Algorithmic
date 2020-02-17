//计算丑数不能被，2，3，5之外的素数整除
//指包含因子2,3,5的正整数被称作丑数  判断方法：首先除2，直到不能整除为止，然后除5到不能整除为止，然后除3直到不能整除为止。最终判断剩余的数字是否为1，如果是1则为丑数，否则不是丑数。
//生成丑数: 2,3,5 乘一个（2，3，5除外）非素数 

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
 
