#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, nq;
	cin >> n;
	int sptable[int(log2(n)+10)][n+10];//Array N²
	int logs[n+1];
	
	
	for(int i = 0; i < n ; i++){// Enchendo a base do Array
		cin >> sptable[0][i];
	}
	cin >> nq;
	
	logs[0] = 0;
	for(int k = 1; k <= n; k++){
		logs[k] = int(log2(k));
	}
	
	
	for(int i = 1; i < int(log2(n)) + 1; i++){
		for(int j = 0; j < n; j++){
			if (j + (1 << (i-1)) >= n){
				break;
			}
			sptable[i][j] = min(sptable[i-1][j], sptable[i-1][j + (1<<(i-1))]);
		}
	}
	
	for(int k = 0; k < nq; k++){
		int L, R, lg;
		cin >> L >> R;
		if( L > R){
			int x = L;
			L = R;
			R = x;
		}
		lg = logs[R-L+1];
		cout << min(sptable[lg][L], sptable[lg][R - (1 << lg)+1]) << endl;
	}
	return 0;
}
