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

void dfs_sum(int vertex, int par, vector<vector<int>> &adj, vector<int> &ans){

    for(auto child : adj[vertex]){
        if(child==par) continue;
        dfs_sum(child,vertex,adj,ans);

        ans[vertex] +=  ans[child]; // children sum to current node
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q; cin>>n>>q;
    vector<vector<int>> adj(n+1);

    for(int i=1;i<n;i++){

        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> dp(n+1,vector<int>(18,0));
    vector<int> level(n+1,0);

    dfs(1,0,adj,dp,level);

    vector<int> ans(n+1,0);


    while(q--){

        int a,b; cin>>a>>b;

        int oa =a ,ob=b;


        if(level[a]>level[b]) swap(a,b);

        int k = level[b]-level[a];



        b = getKpar(b,k,dp);

        int z;
        if(a==b){
            z = a;
        }

        else{
            for(int i=17;i>=0;i--){

                if(dp[a][i] != dp[b][i]){
                    a = dp[a][i];
                    b = dp[b][i];
                }
            }
            z = dp[a][0];
        }

        ans[oa] += 1;
        ans[ob] += 1;
        ans[z] -=1;

        int par_lca = dp[z][0];
        if(par_lca !=0){
            ans[par_lca] -= 1;
        }
    }

    dfs_sum(1,0,adj,ans);
    for(int i=1;i<=n;i++){
        cout << ans[i] << ' ';
    }
    cout << "\n";



    return 0;
}