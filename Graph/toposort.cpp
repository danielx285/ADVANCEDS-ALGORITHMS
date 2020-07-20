#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define tm 1000000000
#define mod 1000000007ll
#define maxn 200005
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> ti;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> tll;

int degree[maxn]; //parents degree
vector<int> adj[maxn]; //adjcency list of directed arests
vector<pi> adj2;// adjcency list of undirected arests
int order[maxn];// order of appearance of the vertices
int n;
vector<int> topo; // topologically ordered vertices
int direct_arests; // number of direct arests

bool toposort(){
    queue<int> mqueue;
    for(int i = 1; i <= n; i++){
        if(degree[i] == 0)
            mqueue.push(i);
    }
    int cnt = 0;
    while(!mqueue.empty()){
        int tp = mqueue.front();
        order[tp] = cnt;
        cnt += 1;
        mqueue.pop();
        topo.push_back(tp);
        for(int i = 0; i < adj[tp].size(); i++){
            degree[adj[tp][i]] -=1;
            direct_arests -= 1;
            if(degree[adj[tp][i]] == 0)
                mqueue.push(adj[tp][i]);
        }
    }
    if(direct_arests == 0){
        return true;
    }
    return false;
}

void cleam(){
    adj2.clear();
    for(int a = 1; a <= n; a++)
        adj[a].clear();
    topo.clear();
    memset(order, 0, sizeof(order));
    memset(degree, 0, sizeof(degree));
    
}

int main(){
    int te;cin >> te;
    for(int i = 0; i < te; i++){
        
        direct_arests = 0;
        int e;
        cin >> n >> e;
        cleam();
        for(int k = 0; k < e; k++){
            int t, u, v;
            cin >> t >> u >> v;
            if(t == 1){
                degree[v] += 1;
                adj[u].push_back(v);
                direct_arests += 1;
            }
            else{
                adj2.push_back({v, u});
            }
        }
        if(toposort()){
            cout << "YES\n";         
            for(int j = 0;  j < adj2.size(); j++){
                if( order[adj2[j].fi] < order[adj2[j].se] ){
                    cout << adj2[j].fi << " " << adj2[j].se << "\n" ;
                }
                else{
                    cout << adj2[j].se << " " << adj2[j].fi << "\n" ;
                }
            }
            for(int i = 1; i <= n ; i++){
                for(int k = 0; k < adj[i].size(); k++){
                    cout << i << " " << adj[i][k] << "\n";
                }
            }
        }
        else{
            cout << "NO\n";
        }
    }    
}
