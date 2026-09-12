#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;  // Changed to 2e5+10 to handle standard CP limits 

// Global variables for basic graph traversals
vector<int> adj[N];
bool vis[N];

/* 
   1. BASIC DFS
    */
void dfs_basic(int vertex) {
    vis[vertex] = 1; // Mark as visited after entering

    for (int child : adj[vertex]) {
        if (vis[child]) continue; // Skip if already visited
        
        // Actions before entering child can go here
        dfs_basic(child);
        // Actions after returning from child can go here
    }
}
==
/* 
   2. IN-TIME AND OUT-TIME (DFS)
    */
map<int, pair<int, int>> time_tree;  // key: node -> {in_time, out_time}
int timer = 0;

void dfs_in_out(int vertex) {
    timer++;
    time_tree[vertex].first = timer; // Record entry time
    vis[vertex] = 1;

    for (int child : adj[vertex]) {
        if (vis[child]) continue;
        dfs_in_out(child);
    }

    // Record exit time after visiting all children
    time_tree[vertex].second = timer;
    timer++;
}

/* 
   3. LEVEL CALCULATION USING DFS
    */
void dfs_level(int vertex, vector<int>& level, int l = 0) {
    vis[vertex] = 1;
    level[vertex] = l; // Store current level

    for (int child : adj[vertex]) {
        if (vis[child]) continue;
        dfs_level(child, level, l + 1);
    }
}

/* 
   4. BASIC BFS (Node and Parent)
   */
void bfs_basic(int root) {
    queue<pair<int, int>> q; // {node, parent}
    q.push({root, 0}); 
    
    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto child : adj[node]) {
            if (child == parent) continue; // Prevent infinite loop back to parent
            q.push({child, node});
        }
    }
}

/* 
   5. BFS WITH LEVEL CALCULATION
    */
void bfs_level_calc(int root) {
    queue<pair<int, int>> q; // {node, parent}
    q.push({root, 0}); 
    int level = 0;
    
    while (!q.empty()) {
        int k = q.size(); // Number of nodes at the current level
        
        for (int i = 0; i < k; i++) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            // Process node here

            for (auto child : adj[node]) {
                if (child == parent) continue;
                q.push({child, node});
            }
        }
        level++; // Increment level after processing all nodes at current depth
    }
}

/* 
   6. BINARY LIFTING PRECOMPUTATION
    */
// Precomputes the 2^i th parent for every node
void build_binary_lifting(int node, int par, vector<vector<int>>& adj_local, vector<vector<int>>& dp, vector<int>& level, int l = 0) {
    
    dp[node][0] = par; // The 2^0 (1st) parent is the direct parent
    level[node] = l;
    
    // Fill the dp table for current node
    // Max 18 bits required for N up to 200,000 (2^17 = 131072)
    for (int i = 1; i <= 17; i++) { 
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }

    for (auto child : adj_local[node]) {
        if (child == par) continue;
        // FIXED: Correct recursive call name
        build_binary_lifting(child, node, adj_local, dp, level, l + 1);
    }
}

/* 
   7. GET K-TH ANCESTOR
    */
// FIXED: Passed 'dp' as a parameter
int getKpar(int node, int k, const vector<vector<int>>& dp) {
    for (int i = 17; i >= 0; i--) {
        if ((k >> i) & 1) {  // If the i-th bit is set in k
            node = dp[node][i]; // Jump 2^i levels up
        }
    }
    return node;
}

/* 
   8. LOWEST COMMON ANCESTOR (LCA) SOLVER
    */
void solve_lca() {
    int n, q; 
    if(!(cin >> n >> q)) return;

    vector<vector<int>> adj_local(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj_local[u].push_back(v);
        adj_local[v].push_back(u);
    }

    // dp[node][i] stores the 2^i th ancestor
    vector<vector<int>> dp(n + 1, vector<int>(18, 0)); 
    vector<int> level(n + 1, 0);

    build_binary_lifting(1, 0, adj_local, dp, level);

    while (q--) {
        int a, b; 
        cin >> a >> b;

        // 1. Bring both nodes to the same level
        if (level[a] > level[b]) swap(a, b);
        int k = level[b] - level[a];
        
        // FIXED: passed dp to getKpar
        b = getKpar(b, k, dp); 

        // 2. If they are the same node, that node is the LCA
        if (a == b) {
            cout << a << "\n";
            continue;
        }

        // 3. Jump together until they are just below the LCA
        // FIXED: Loop MUST go down to 0, not 1.
        for (int i = 17; i >= 0; i--) {
            if (dp[a][i] != dp[b][i]) {
                a = dp[a][i];
                b = dp[b][i];
            }
        }

        // The LCA is the direct parent of a (and b)
        cout << dp[a][0] << "\n";
    }
}

int main() {
    // Optimize standard I/O operations for speed
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Call your required solver here
    // solve_lca();

    return 0;
}