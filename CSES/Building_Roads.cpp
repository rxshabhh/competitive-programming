#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
vector<vector<int>> adj;
vector<bool> vis;

void dfs(int u){
    vis[u] = true;

    for(auto child : adj[u]){

        if(vis[child]) continue;
        dfs(child);
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    adj.resize(n+1);
    vis.assign(n+1,false);

    for(int i=1;i<=m;i++){
        int a,b; cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> leaders;

    for(int i=1;i<=n;i++){

        if(!vis[i]){
            leaders.push_back(i);
            dfs(i);
        }
    }

    int k = leaders.size()-1;

    cout << k << "\n";

    for(int i=0;i<k;i++){
        cout << leaders[i] << " " << leaders[i+1] << "\n";
    }
    

    return 0;
}