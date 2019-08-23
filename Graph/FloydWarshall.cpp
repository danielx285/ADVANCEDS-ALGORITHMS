#include <bits/stdc++.h>
#define INF 55555555
using namespace std;

long long matrix[100][100];

int main(){
	string s,t;
	cin >> s >> t;
	for(int i = 0;i < 100;i++)
		for(int j = 0;j < 100; j++)
			matrix[i][j] = INF;
	int n ;
	cin >> n;
	for(int i = 0;i < n; i++){
		int a, b, c;
        cin >> a >> b >> c;
        matrix[a][b] = c;
	}

	for(int k = 0;k < 100;k++)
		for(int i = 0;i < 100;i++)
			for(int j = 0;j < 100;j++){
				//cout << k << " " << i << " " << j << endl;
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
    int qtd_querys;
    cin >> qtd_querys ;
    for(int i = 0; i < qtd_querys; i++){
        int a, b;
        cin >> a >> b;
        int c = matrix[a][b];
        cout << "Shortest path between " << a << " and " << b << " is " << c << endl;
    }

	return 0;
}