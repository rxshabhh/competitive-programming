#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int ans=0;

void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& a, int m, int streak){

    if(a[node]==1){
        streak++;
    }
    else streak=0;

    if(streak>m) return;

    bool is_leaf = true;

    for(auto child : adj[node]){
        if(child==par) continue;

        is_leaf = false;

        dfs(child,node,adj,a,m,streak);
    }

    if(is_leaf) ans++;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin>>n>>m;

    vector<int> a(n+1);

    for(int i=1;i<=n;i++) cin>>a[i];

    vector<vector<int>> adj(n+1);
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0,adj,a,m,0);

    cout << ans;



    return 0;
}