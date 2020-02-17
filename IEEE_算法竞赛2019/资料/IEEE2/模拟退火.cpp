

#include<cstdio>
#include<cmath>

using namespace std;
double dis(long long a,long long b,long long c,long long d)
{
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}
int main()
{
   long long x1,x2,x3,y1,y2,y3;
   scanf("%lld %lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&x3,&y3);
   printf("%.6f\n",dis(x1,y1,x3,y3)+2*dis(x2,y2,x3,y3));
   return 0;
}

