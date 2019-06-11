#include <bits/stdc++.h>
#define MAXN 200005
using namespace std;

const long double eps = 1e-7;

int sgn(long double x){
	if(x < -eps)
		return -1;
	else if(x > eps)
		return 1;
	return 0;
}

int cmp(long double a, long double b){
	return sgn(a-b);
}

int main(){
	double a = 1 +  4.0/3.0;
	double b = 1.0 + 1.0 + 1.0/3.0; 
	
	if(cmp(a, b) == 0)
		printf("%.20f is relatively equal to %.20f\n", a, b ) ;
	else if(cmp(a, b) == -1)
		printf("%.20f is less than %.20f\n", a, b ) ;
	else
		printf("%.20f is greater than %.20f\n", a, b ) ;
	
	a -= 0.0000005;
	
	if(cmp(a, b) == 0)
		printf("%.20f is relatively equal to %.20f\n", a, b ) ;
	else if(cmp(a, b) == -1)
		printf("%.20f is less than %.20f\n", a, b ) ;
	else
		printf("%.20f is greater than %.20f\n", a, b ) ;
	
	a += 0.0000010;
	
	if(cmp(a, b) == 0)
		printf("%.20f is relatively equal to %.20f\n", a, b ) ;
	else if(cmp(a, b) == -1)
		printf("%.20f is less than %.20f\n", a, b ) ;
	else
		printf("%.20f is greater than %.20f\n", a, b ) ;
}
