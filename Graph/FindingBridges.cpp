#include <bits/stdc++.h>
#define UNVISITED -1

using namespace std;

int n, cont, root, rootChildren, cBridges;

void findingBridge(int u, int pai[], int low[], int num[], vector<int> adj[]){
	low[u] = num[u] = cont++;
	for(int i = 0, v; i < (int)adj[u].size(); i++){
		v = adj[u][i];
		if(num[v] == UNVISITED){
			pai[v] = u;
			if(u == root) 
				rootChildren++;
			findingBridge(v, pai, low, num, adj);
			
			if(low[v] > num[u])
				cout << "Bridge between " << min(u, v) << " and " << max(u, v) << endl;
			low[u] = min(low[u], low[v]);
            cBridges += 1;
		}
		
		else if(v != pai[u]){
			low[u] = min(low[u], num[v]);
		}
	}
}


int main(){
	
    cin >> n;
    cont = 0;
    int pai[n+1], low[n+1], num[n+1];
    memset(&num, UNVISITED, sizeof num);
    memset(&pai, 0, sizeof pai);
    memset(&low, 0, sizeof low);
    vector<int> adj[n+1] ; 
    
    for(int i = 0; i < n; i++){
        int v;
        int qtd;
        cin >> v >> qtd;
        for(int i = 0; i < qtd; i++){
            int u;
            cin >> u;
            adj[v].push_back(u);
        }
    }
    
    for(int i = 0; i < n; i++){
        if(num[i] == UNVISITED){
            root = i; rootChildren = 0;  findingBridge(i ,pai, low, num, adj);
        }
    }

	return 0;	
}