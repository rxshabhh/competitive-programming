#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
const int N = 2e5 +10;

vector<vector<int>> adj;

int vis[N];
int ans=0;

void dfs(int vertex, int par=0){

    

    for(auto child : adj[vertex]){

        if(child==par) continue;
        
        dfs(child,vertex);

        
    }

    if(par!=0 && !vis[vertex] && !vis[par]){
        ans++;
        vis[vertex] = 1;
        vis[par] =1;
    }



}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    adj.resize(n+1);

    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);


    }

    dfs(1,0);

    cout <<ans <<"\n";
    

    

    return 0;
}