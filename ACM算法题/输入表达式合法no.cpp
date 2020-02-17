#include <bits/stdc++.h>
using namespace std;

bool isnumber(char ch)
{
	return (ch<='9'&&ch>='0');
}
bool MatchCalculate(char exp[])
{
	stack <char> q,p;
	int i=0;
	bool match=true;
	while (exp[i]!='\0'&&match)
	{
		switch(exp[i])
		{
			case '(':
				q.push(exp[i]);
				p.push(exp[i]);break;
			case ')':
				p.push(')');
				match=false;
				while (q.empty()==false)
				{
					if (q.top()=='(')
					{
						match=true;
						q.pop();
						break;
					}
					q.pop();
				}
				break;
			case '-':case'+':case '*':case '/':
				if (p.empty()==false&&exp[i+1]!='\0'&&(p.top()==')'||isnumber(p.top()))&&(exp[i+1]=='('||isnumber(exp[i+1]))){
						q.push(exp[i]);
						p.push(exp[i]);
				}
				else
				{
					match=false;
					break;
				}
				break;
			case '1':case'2':case '3':case'4':case'5':case'6':case'7':case'8':case'9': case'0':
				if((p.empty()==false&&p.top()!=')')||(exp[i+1]!='\0'&&exp[i+1]!='('){
						q.push(exp[i]);
						p.push(exp[i]);
				}
				break;
			case ' ':break;
			default:match=false;break;
		}
		i++;
	}
	while(q.empty()==false)
	{
		if (q.top=='(')
		{
			match==false;
			break;
		}
	}
	return match;
}

int main(void)
{
	
	return 0;
}
