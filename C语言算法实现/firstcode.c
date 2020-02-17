#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
srand(time(NULL));
int a,b,n;
l:
printf("You need to enter the right answer.Or it won't exit.\n");
a=rand()%100;
b=rand()%100;
printf("%d + %d =? answer: ",a,b);
scanf("%d",&n);
if((a+b)==n)
{
printf("Congratulations! Have you a good day.\n");
return 0;}
else goto l;

return 0;
}

