#include <bits/stdc++.h>  // ios_base::sync_with_stdio(false);
#define MAXN 10000        // cin.tie(NULL);
#define di pair<int, int>
#define tri pair<di, int>
using namespace std;
void swap(int ar[],int  i,int j)
    {int aux = ar[j]; ar[j] = ar[i]; ar[i] = ar[j];}

int parents[MAXN + 1];
int lens[MAXN + 1];

void build(){
    for(int k = 1; k <= MAXN; k++)
        parents[k] = k;
}

int find(int v){
    if(v == parents[v])
        return v;
    parents[v] = find(parents[v]);
    return parents[v];
}

void uni(int v, int u){
    int parentV = find(v);
    int parentU = find(u);
    
    if(parentV == parentU)
        return;
    
    else if( lens[parentV] < lens[parentU]){
        parents[parentV] = parents[parentU];
        lens[parentU] += lens[parentV];
    }

    else{
        parents[parentU] = parents[parentV];
        lens[parentV] += lens[parentU];
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    build();

    int n, m, u, v, c;
    cin >> n >> m;
    tri edges[m];

    for(int k = 0; k < m; k++){
        cin >> u >> v >> c;
        edges[k] = {{c, u}, v};
    }
    
    sort(edges , edges+m);
    
    int dist = 0;

    for(int k = 0; k < m; k++){
        u = edges[k].first.second;
        v = edges[k].second;
        c = edges[k].first.first;
        if(find(u) != find(v)){
            uni(u, v);
            dist += c;
        }
    }

    cout << dist << endl;
    return 0;
}
