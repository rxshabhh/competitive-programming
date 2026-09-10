#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dp_on_trees(int node, vector<vector<int>>& adj, int par, vector<int>& dp){

    dp[node] =1;
    for(auto it : adj[node]){

        if(it==par) continue;
        dp_on_trees(it,adj,node,dp);
        dp[node] += dp[it];
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<vector<int>> adj(n+1);

    for(int i=2;i<=n;i++){

        int x; cin>>x;

        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    vector<int> dp(n+1,0);
    dp_on_trees(1,adj,0,dp);

    for(int i=1;i<=n;i++){
        cout << dp[i]-1 << " ";
    }
    cout << "\n";



    return 0;
}