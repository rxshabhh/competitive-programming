#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> adj;
map<pair<int,int>,int> mpp;
vector<int> dp;

void dfs(int node, int par){

    for(auto child : adj[node]){

        if(child==par) continue;

        if(mpp[{par,node}] < mpp[{node,child}]){
            dp[child] = dp[node];
        }
        else dp[child] = 1+ dp[node];

        dfs(child,node);
    }


}


void solve(){

    int n; cin>>n;

    adj.assign(n,vector<int>());
    dp.assign(n,0);
    mpp.clear();


    for(int i=0;i<n-1;i++){

        int u,v; cin>>u>>v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);

        mpp[{u,v}] =i;
        mpp[{v,u}] = i;
    }

    dp[0]=1;
    // dp[i] is the no. of iteration for making ith edge 

    mpp[{-1,0}] = -1; // assumption: parent of root has edge index -1

    dfs(0,-1);

    cout << *max_element(dp.begin(),dp.end()) << "\n";

    



}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;

    while(t--){
        solve();
    }

    return 0;
}