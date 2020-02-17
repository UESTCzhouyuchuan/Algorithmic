#include<stdio.h>

int main(void){
int n,p,q;
int table_number;
while(scanf("%d %d %d",&n,&p,&q)==3){
table_number=0;
if(n%2==0){
table_number+=n/2;
table_number+=((p+q)%4?((p+q)/4+1):((p+q)/4));
}
else{
table_number+=(n/2+1);
if(p==0&&q!=0)
table_number+=((q-1)%4?((q-1)/4+1):((q-1)/4));
if(q==0&&p!=0)
table_number+=((p-1)%4?((p-1)/4+1):((p-1)/4));
if(q!=0&&p!=0)
table_number+=((p+q-2)%4?((p+q-2)/4+1):((p+q-2)/4));
}
printf("%d\n",table_number);
}

return 0;
}