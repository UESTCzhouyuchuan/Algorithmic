//内置枚举全排列函数
#include<bits/stdc++.h>
#define MAX 3
using namespace std;
int a[MAX];

void myPermutation(){
  srand((unsigned)time(NULL));
  for (int i=0 ;i <MAX;i++)
    a[i]=i;
  do {
    for ( int i=0;i<MAX;i++)
      printf("%d ",a[i]);
    printf("\n");
  }while(next_permutation(a,a+MAX));

}
int main(){
  myPermutation();
  return 0;
}