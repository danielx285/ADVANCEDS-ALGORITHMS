#include <bit/stdc++.h>

using namespace std;

int GCD(int a, int b){
  if( b == 0) return b;
  return GCD(b, a%b);
}

int LCM(int a, int b){
  return a / GCD(a, b) * b;
}


int main(){
  int a, b;
  cin >> a >> b;
  cout << LCM(a, b);
  
  return 0;
}
