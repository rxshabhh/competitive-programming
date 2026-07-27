#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5 + 10;

vector<vector<int>> adj;


int temp_depth[N];
int depthA[N];
int depthB[N];

void dfs(int vertex, int par, int current_d, int d[]) {
    d[vertex] = current_d; 
    for(auto child : adj[vertex]) {
        if(child == par) continue;
        
   
        dfs(child, vertex, current_d + 1, d);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;

    adj.resize(n + 1);

    for(int i = 1; i < n; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0, temp_depth);
    
    int mx = -1;
    int nodeA = 1;
    for(int i = 1; i <= n; i++) {
        if(mx < temp_depth[i]) {
            mx = temp_depth[i];
            nodeA = i;
        }
    }

    dfs(nodeA, 0, 0, depthA);
    
    mx = -1;
    int nodeB = 1;
    for(int i = 1; i <= n; i++) {
        if(mx < depthA[i]) {
            mx = depthA[i];
            nodeB = i;
        }
    }

    dfs(nodeB, 0, 0, depthB);

    for(int i = 1; i <= n; i++) {
        cout << max(depthA[i], depthB[i]) << " ";
    }
    cout << "\n";

    return 0;
}