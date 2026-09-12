#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& depth){

    for(auto child : adj[node]){
        if(child==par) continue;

        depth[child] = depth[node] +1;

        dfs(child,node,adj,depth);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<vector<int>> adj(n+1);

    for(int i=1;i<n;i++){

        int u,v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n+1,0);

    dfs(1,0,adj,depth);

    int mx=-1;
    int node;

    for(int i=1;i<=n;i++){

        if(mx<depth[i]){
            mx = depth[i];
            node =i;
        }

        depth[i] =0;
    }

    dfs(node,0,adj,depth);

    for(int i=1;i<=n;i++){
        if(mx<depth[i]){
            mx = depth[i];
            node =i;
        }

        depth[i] = 0;
    }

    cout << mx << "\n";

    



    return 0;
}