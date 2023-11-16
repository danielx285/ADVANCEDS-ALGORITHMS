#include <bits/stdc++.h>
#define MAX 200001
#define pii pair<int, int>
#define LL long long
#define tlii pair<LL, pii>
#define INF 2e18

using namespace std;

vector<int> result;
vector<tlii> matrix[MAX];
vector<LL> dists(MAX,  INF);
int n;
struct  compare
{
    bool operator()(tlii A, tlii B){return A.first > B.first;}
};

void dijkistra(){
    priority_queue<tlii, vector<tlii>, compare> pq;
    pq.push({0, {1, 0}});
    tlii top;
    dists[1] = 0;
    while(! pq.empty()){
        top = pq.top();
        pq.pop();
        int node = top.second.first;
        LL dist = top.first;
        int aresta = top.second.second;
        if(dist != dists[node] )
            continue;
        result.push_back(aresta);
        for(int i =0; i < matrix[node].size(); i++){
            int v = matrix[node][i].second.first;
            LL distv = matrix[node][i].first;
            if(dist + distv < dists[v]){
                dists[v] = dist + distv;
                pq.push({dists[v], {v, matrix[node][i].second.second}});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);

    int m, a, b, c;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        matrix[a].push_back({c, {b, i+1}});
        matrix[b].push_back({c, {a, i+1}});
    }
    dijkistra();
    for(int i = 1; i < n; i++){
        cout << result[i] << " ";
    }
}
