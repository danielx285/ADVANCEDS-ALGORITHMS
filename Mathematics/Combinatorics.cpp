#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int exp(int a, int b){
	if(b == 0) return 1;
	if(b % 2 == 0){
		li x = exp(a, b/2);
		return (x  *  x ) % MOD; 
	}
	return (exp(a, b-1) * (a) % MOD;
}

//Fermat's little theorem to inverse modular
int DivMod(a, b){
    return (a * exp(b, MOD - 2)) % MOD;
}

int PgSum(int a1 , int q, int n){
    return DivMod( a1*(exp(q, n) -1 ) % MOD , q - 1)  ;
}

int main(){
  cout << PgSum(3, 2, 4) << endl;
}
