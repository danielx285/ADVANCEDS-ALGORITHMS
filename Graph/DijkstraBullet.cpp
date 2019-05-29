#include <bits/stdc++.h>
#define MAXN 500005
#define di pair<int, int>
#define tri pair<int, di>
#define ll long long
#define tlii pair<ll, di >

using namespace std;

vector<di> matrix[MAXN];
bool seen[MAXN];
int parents[2 * MAXN];

struct compare{bool operator()(tlii A, tlii B){return A.first > B.first;}};

int dijkstra(int v0,int v1){
    priority_queue<tlii, vector<tlii>, compare> pq;
    pq.push({0,{v0, 0}});
    if(v0 == v1) return 1;
    
    while(! pq.empty()){
        tlii top = pq.top();
        pq.pop();

        int node = top.second.first;
        int path = top.second.second;
        ll distance = top.first;
        
        if(seen[node])
            continue;
        
        parents[node] = path; 
        
        if(node == v1)
            return node;

        seen[node] = true;
        for(int i = 0; i < matrix[node].size(); i++){
            int v = matrix[node][i].first;
            if(! seen[v])
                pq.push({distance + matrix[node][i].second, {v, node}});
        }
    }
    return 0;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int nNodes, mEdges;    
    cin >> nNodes >> mEdges;

    int a, b, c;
    for(int k = 0; k < mEdges; k++){
        cin >> a >> b >> c;
        matrix[a].push_back({b, c});
        matrix[b].push_back({a, c});
    }
    int result = dijkstra(1, nNodes);
    if( result ==  0)
        cout << "there is no way possible!";
    else if(result == 1)
        cout << 1;
    else{
        vector<int> output;
        output.push_back(result);
        int i = result;
        while(parents[result]){ 
            result = parents[result];
            output.push_back(result);
        }

        for(int i = output.size() - 1; i >= 0; i--){
            cout << output[i] << " ";
        }
    }
    return 0;
}
