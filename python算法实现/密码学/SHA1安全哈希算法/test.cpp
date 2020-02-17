#include <bits/stdc++.h>

using namespace std;

int main(){
  string A("");
  cin >> A;
  unsigned long B = (unsigned long )A[0]^0xff;
  cout << A;
  printf("\n%x", B);
  return 0;
}