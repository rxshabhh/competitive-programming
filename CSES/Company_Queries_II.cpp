#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// LCA with Binary Lifting implementation



void dfs(int vertex, int par, const vector<vector<int>> &adj, vector<vector<int>> &dp, vector<int> &level, int l=0){

    dp[vertex][0] = par;

    for(int i=1;i<=17;i++){
        dp[vertex][i] = dp[dp[vertex][i-1]][i-1];
    }
    level[vertex]=l;

    for(auto child : adj[vertex]){

        if(child == par) continue;

        dfs(child,vertex,adj,dp,level,l+1);

    }

}

int getKpar(int x, int k, vector<vector<int>> &dp){
    for(int i=17;i>=0;i--){
        if((k>>i)&1){
            x = dp[x][i];
        }
    }

    return x;
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
    vector<int> level(n+1,0);

    dfs(1,0,adj,dp,level);


    while(q--){

        int a,b; cin>>a>>b;

        if(level[a]>level[b]) swap(a,b);

        int k = level[b]-level[a];



        b = getKpar(b,k,dp);

        if(a==b){
            cout << a << "\n";
            continue;
        }

        for(int i=17;i>=0;i--){

            if(dp[a][i] != dp[b][i]){
                a = dp[a][i];
                b = dp[b][i];
            }
        }
        cout << dp[a][0] << "\n";
    }



    return 0;
}