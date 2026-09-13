#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> adj;
vector<int> par;

vector<bool> vis;
int cycle_start = -1, cycle_end;


bool dfs(int node, int p){

    vis[node] = true;

    for(auto child : adj[node]){

        if(child == p) continue;

        if(vis[child]){

            cycle_start = child;
            cycle_end = node;
            return true;
        }

        else{
            par[child] = node;
            if(dfs(child,node)) return true;

        }
    }

    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;

    adj.resize(n+1);
    par.assign(n+1,-1);
    vis.assign(n+1,false);

    for(int i=0;i<m;i++){

        int u,v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for(int i=1;i<=n;i++){

        if(!vis[i] && dfs(i,-1)) break;
    }

    if(cycle_start == -1){
        cout << "IMPOSSIBLE";

    }

    else{

        vector<int> cycle;

        cycle.push_back(cycle_start);

        int curr = cycle_end;

        while(curr != cycle_start){
            
            cycle.push_back(curr);
            curr = par[curr];
        }

        cycle.push_back(cycle_start);

        reverse(cycle.begin(),cycle.end());

        

        cout << cycle.size() << "\n";

        for(int val : cycle){
            cout << val << " ";
        }
    }



    

    return 0;
}