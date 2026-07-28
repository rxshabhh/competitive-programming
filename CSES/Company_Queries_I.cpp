#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// Binary Lifting implementation



void dfs(int vertex, int par, const vector<vector<int>> &adj, vector<vector<int>> &dp){

    dp[vertex][0] = par;

    for(int i=1;i<=17;i++){
        dp[vertex][i] = dp[dp[vertex][i-1]][i-1];
    }

    for(auto child : adj[vertex]){

        if(child == par) continue;

        dfs(child,vertex,adj,dp);

    }

}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q; cin>>n>>q;
    vector<vector<int>> adj(n+1);

    for(int i=2;i<=n;i++){

        int x; cin>>x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }

    vector<vector<int>> dp(n+1,vector<int>(18,0));

    dfs(1,0,adj,dp);


    while(q--){

        int x,k; cin>>x>>k;

        for(int i=17;i>=0;i--){
            if((k>>i)&1){
                x = dp[x][i];
            }
        }

        if(x!=0) cout << x << "\n";
        else cout << -1 << "\n";
    }



    return 0;
}