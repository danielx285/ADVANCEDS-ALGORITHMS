#include <bits/stdc++.h>
#define eps 0.00000001
#define indef 46876.4847688
 
using namespace std;
 
int sgn(long double x){
	if(x < -eps) return -1;
	else if(x > eps) return 1;
	else return 0;
}
 
bool equals(long double a, long double b){
	if( sgn(a-b) == 0)return true;
	else return false;
}
 
struct pt{
	
	long double x, y;
	pt(){}
	pt(long double x, long double y){
		this->x = x; this->y = y;
	}
	long double cofA(pt p){
		if( this->x == p.x )
			return indef;
		else
			return (this->y - p.y)/(this->x - p.x);
	}
};
 
struct line{
	long double A;
	long double B = 0;
	long double X = 100001;
	line(){}
	line(pt a, pt b){
		if(a.x == b.x){
			this->A = 0;
			this->X = a.x;
		}
		else{
			this->A = a.cofA(b);
			this->B = a.y - (this->A*a.x);
		}
	}
};
 
bool operator<(const line &l, const line &l2){
	if( l.X == l2.X && l.X == 100001 ){
		if(sgn(l.A - l2.A) == -1)
			return true;
		if(sgn(l.A - l2.A) == 1)
			return false;
		if(sgn(l.A - l2.A) == 0){
			if(sgn(l.B - l2.B) == - 1)
				return true;
			else
				return false;
		}		
	}
	else if(l.X != l2.X && l.X == 100001){
		return true;
	}
	else if(l.X != l2.X && l2.X == 100001){
		return false;
	}
	else{
		if(sgn(l.X - l2.X) == -1)
			return true;
		else
			return false;
	}
}
 
int main(){
	int n, hsx, hsy;
	cin >> n >> hsx >> hsy;
	pt a = pt(hsx, hsy);
	
	set<line> m7;
	
	for(int i = 0; i < n; i++){
		cin >> hsx >> hsy;
		pt aux = pt(hsx, hsy);
		line l = line(a, aux);
		//cout << " " <<  l.A << " " << l.B << " " << l.X << endl;
		m7.insert(l);
	}
	
	cout << m7.size() << endl;
}
