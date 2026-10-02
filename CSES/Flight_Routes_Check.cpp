#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> g, rg;
vector<int> vis, comp, ord;

void dfs1(int u) { 
    vis[u] = 1; 
    for(int v : g[u]) {
        if(!vis[v]) dfs1(v); 
    }
    ord.push_back(u); 
}

void dfs2(int u, int c) {
    comp[u] = c; 
    for(int v : rg[u]) {
        if(comp[v] < 0) dfs2(v, c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    if(!(cin >> n >> m)) return 0;

    // 1-based indexing setup
    g.resize(n + 1);
    rg.resize(n + 1);
    vis.assign(n + 1, 0);
    comp.assign(n + 1, -1);

    // Build both the original graph and the reversed graph
    for(int i = 0; i < m; i++){
        int x, y; 
        cin >> x >> y;
        g[x].push_back(y);
        rg[y].push_back(x); // Add to reversed graph
    }

    // Step 1: Run DFS on the original graph to get finishing times
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) dfs1(i);
    }

    // Step 2: Reverse the order of finishing times
    reverse(ord.begin(), ord.end()); 
    
    // Step 3: Run DFS on the reversed graph to find SCCs
    int C = 0;
    for(int u : ord) {
        if(comp[u] < 0) {
            dfs2(u, C++);
        }
    }

    // --- CSES FLIGHT ROUTES CHECK LOGIC ---
    if (C == 1) {
        // Only 1 Strongly Connected Component exists
        cout << "YES\n";
    } else {
        // More than 1 SCC exists.
        cout << "NO\n";
        
        // Component 0 is a topological "source" in the original graph.
        // Component 1 is either downstream or completely disconnected.
        // Therefore, you cannot reach Component 0 from Component 1.
        int node_in_0 = -1, node_in_1 = -1;
        
        for (int i = 1; i <= n; i++) {
            if (comp[i] == 0) node_in_0 = i;
            if (comp[i] == 1) node_in_1 = i;
        }
        
        // Output a node from SCC 1 and a node from SCC 0
        cout << node_in_1 << " " << node_in_0 << "\n";
    }

    return 0;
}