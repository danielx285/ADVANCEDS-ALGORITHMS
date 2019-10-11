#include <bits/stdc++.h> //LCA O(N.log(N))
#define f first         //Calcule the minimal distance between two node on tree with weight using 
#define s second       // Lowest Common Ancestor(LCA) , queries O(logN)
#define pb push_back  // Leonardo Su 
#define mp make_pair // Github : @Leonardosu
#define N 100010
#define M 16
using namespace std;
typedef long long int ll;
typedef pair<int,ll> ii;

int nivel[N],pai[N],dp[N][M];
int n,m,q,a,b;

vector<ii> grafo[N];
ll dist[N],ans,x;

void dfs(int x){

    for(int i=0;i<grafo[x].size();++i){
        int y=grafo[x][i].f;
        ll d=grafo[x][i].s;
        if(nivel[y]==-1){

            pai[y]=x;
            nivel[y]=nivel[x]+1;
            dist[y]=dist[x]+d;    
            dfs(y);
        }
    }
}

int lca(int u,int v){

    if(nivel[u]<nivel[v]) swap(u,v);

    for(int i=M-1;i>=0;--i)
        if(nivel[u]-(1<<i)>=nivel[v])
            u=dp[u][i];

    if(u==v) return u;

    for(int i=M-1;i>=0;--i)
        if(dp[u][i]!=-1 && dp[u][i]!=dp[v][i])
            u=dp[u][i],v=dp[v][i];

    return pai[u];
}

int main(){

    ios_base::sync_with_stdio(false); cin.tie(0);

    while(cin>>n && n){

        for(int i=0;i<n;++i){   // clear
            nivel[i]=pai[i]=-1,dist[i]=0;
            grafo[i].clear();
        }

        for(int i=0;i<n;++i) // memset
            for(int j=0;j<M;++j)
                dp[i][j]=-1;

        for(int i=1;i<=n-1;++i){   //input
            cin>>a>>x;
            grafo[i].pb(mp(a,x));
            grafo[a].pb(mp(i,x));
        }

        nivel[0]=0;
        dfs(0);

        for(int i=0;i<n;++i)
            dp[i][0]=pai[i];

        for(int j=1;j<M;++j)
            for(int i=0;i<n;++i)
                dp[i][j]=dp[dp[i][j-1]][j-1];

        cin>>q;

        for(int i=1;i<=q;++i){  //queries
            ans=0;
            cin>>a>>b;
            ans = dist[a] + dist[b] - 2*dist[lca(a,b)];
            cout<<ans;
            if(i!=q)
                cout<<" ";
        }

        cout<<"\n";
    }

}