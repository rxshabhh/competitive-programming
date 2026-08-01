#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> adj;

double ans = 0.0;

void dfs(int vertex, int par,int depth, double prob){

    int cnt =0;
    if(vertex==1){
        cnt += adj[vertex].size();
    }
    else cnt += adj[vertex].size()-1;

    if(cnt==0){
        ans += depth*prob;
        return;
    }

    double prob_child = prob/cnt;

    for(auto child : adj[vertex]){
        if(child == par) continue;

        dfs(child,vertex,depth+1,prob_child);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    adj.resize(n+1);

    int level[n+1];


    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0,0,1.0);

    cout << fixed << setprecision(15) << ans << '\n';


    

    return 0;
}