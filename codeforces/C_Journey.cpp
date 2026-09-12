#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double ans = 0.0;

void dfs(int node, int par, vector<vector<int>>& adj, double cur_prob, int length=0){

    int choice = (node==1) ? adj[1].size() : adj[node].size()-1;

    bool is_leaf = true;


    for(int child : adj[node]){

        if(child == par) continue;

        is_leaf = false;

        double new_prob = cur_prob / choice;
        dfs(child,node,adj,new_prob,length+1);
    }

    if(is_leaf)
    {
        ans += (cur_prob*length);
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

    dfs(1,0,adj,1);

    cout << fixed << setprecision(15) << ans;



    return 0;
}