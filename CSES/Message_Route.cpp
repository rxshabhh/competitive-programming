#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> adj;
    vector<bool> vis;

    int n,m; cin>>n>>m;

    adj.resize(n+1);

    for(int i=0;i<m;i++){

        int u,v; cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vis.assign(n+1,false);

    queue<int> q;

    q.push(1);

    vis[1]= true;

    vector<int> par(n+1,-1);

    bool found = false;

    while(!q.empty() && !found){

        int u = q.front();
        q.pop();

        for(auto v : adj[u]){

            if(!vis[v]){
                vis[v] = true;
                par[v] = u;
                q.push(v);

                if(v==n){
                    found = true;
                    break;
                }

            }
        }
    }

    if(found == false) cout << "IMPOSSIBLE";

    else{

        vector<int> path;
        int curr = n;

        while(curr != -1){

            path.push_back(curr);

            curr = par[curr];
        }

        reverse(path.begin(),path.end());

        cout << path.size() << "\n";

        for(auto val : path){

            cout << val << " ";
        }
    }



    return 0;
}