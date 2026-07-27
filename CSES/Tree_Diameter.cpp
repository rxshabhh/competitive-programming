#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
const int N = 2e5 +10;

vector<vector<int>> adj;

int depth[N];



void dfs(int vertex, int par=-1){

    

    for(auto child : adj[vertex]){
        if(child==par) continue;

        depth[child] = depth[vertex] +1;

        
        dfs(child,vertex);
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

    dfs(1);

    int mx = -1;
    int node;

    for(int i=1;i<=n;i++){

        if(mx<depth[i]){
            mx = depth[i];
            node = i;
        }

        depth[i]=0;
    }

    dfs(node);

    for(int i=1;i<=n;i++){

        if(mx<depth[i]){
            mx = depth[i];
            node = i;
        }

        depth[i]=0;
    }

    cout << mx << "\n";



    

    return 0;
}