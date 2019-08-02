#include <bits/stdc++.h>
#define MAX 1000007
 
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
 
struct st{
    ll h[MAX], power[MAX], inv[MAX];
    ll base[2] = {317, 307};
    ll mod[2] = {104000717, 104000711};
    
    ll inverse(int a, int b, int s0 = 1, int s1 = 0){
        return b == 0? s0: inverse(b, a%b, s1, s0-s1*(a/b));
    }
 
    void init(){
        power[0] = inv[0] = 1;
        power[1] = base[0];
        inv[1] = inverse(base[0], mod[0]);
 
        for(int i = 2; i < MAX; i++){
            power[i] = (power[i-1]*power[1])%mod[0];
            inv[i] = (inv[i-1]*inv[1])%mod[0];
        }
    }
 
    ll build(string &s){
        h[0] = s[0];
        for(int i = 1; i < s.size(); i++){
            h[i] = (h[i-1] + (s[i]*power[i])%mod[0])%mod[0];
        }
 
        return h[s.size()-1];
    }
 
    ll sub(int l, int r){
        ll hr = h[r];
        ll hl = (l > 0)? h[l-1]:0;
        ll ans = ((hr+mod[0] - hl) * inv[l])%mod[0];
        return ans;
    }
} A, B, C;
 
int solve(string x, string y, string z){
	A.init();
	A.build(x);
	B.init();
	B.build(y);
	C.init();
	C.build(z);
	
	int total = x.size() + y.size() + z.size();
	
	int j = 0;
	int save = -1;
	while(j  < x.size() &&  j < y.size()){
		if( A.sub( x.size() - j - 1 , x.size() - 1) == B.sub(0, j))
			save = j;
			
		
		j +=1;
	}
	
	for(int i = save + 1 ; i < y.size(); i++)
		x += y[i];
		
	B.init();
	B.build(x);
	int i = 0;
	int save1 = -1;
	while(i  < x.size() &&  i < z.size()){
		if( B.sub( x.size() - i - 1 , x.size() - 1) == C.sub(0, i))
			save1 = i;
		
		
		i +=1;
	}
	
	int k = 0;
	int save2 = -1;
	while(k  < x.size() &&  k < z.size()){
		if( C.sub( z.size() - k - 1 , z.size() - 1) == B.sub(0, k))
			save2 = k;
		
		k +=1;
	}
	
	return total - save - max(save1, save2) - 2;
}
 
int main(){
    string ar[3];
    cin >> ar[0] >> ar[1] >> ar[2];
    sort(ar, ar+3);
	int mini = solve(ar[0], ar[1], ar[2]);
	
    while(next_permutation(ar, ar + 3)){
		int aux = solve(ar[0], ar[1], ar[2]);
		if( aux < mini)
			mini = aux;
	}
 
	cout << mini << endl;
}
