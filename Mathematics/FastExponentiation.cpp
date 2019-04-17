#include <bits/stdc++.h>
#define li long int
#define MOD 1000000007 

using namespace std;

li fastexp(li a, li b){
	if(b == 0) return 1;
	if(b % 2 == 0){
		li x = fastexp(a, b/2);
		return ((x % MOD) *  (x % MOD)) % MOD; 
	}
	return ((fastexp(a, b-1) % MOD) * (a % MOD))% MOD;
}


int main(){
	
	li base, expoente;
	cin >> base >> expoente;
	cout <<  fastexp(base, expoente) << "\n";

	return 0;
}
