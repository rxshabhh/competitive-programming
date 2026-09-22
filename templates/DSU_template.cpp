#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5+10;

/*    
    BASIC DSU
   ---------------------------------------------------------------------
   parent[v] : node v points to; a node pointing to itself is a ROOT
   sz[v]     : size of the set whose root is v   (valid only for roots)
   rnk[v]    : upper bound on tree height        (only for union by rank)
   comps     : current number of components      (starts at n)
   mx        : size of the largest component     (starts at 1)
   ===================================================================== */

int parent[N];
int sz[N];
int rnk[N];
int comps, mx;

// creates a set containing only v; call for every node before any union
void make(int v){
    parent[v] = v;
    sz[v] = 1;
    rnk[v] = 0;
}

// call once per test case: builds n singleton sets (1-indexed)
void init(int n){
    for(int i = 1; i <= n; i++) make(i);
    comps = n;
    mx = 1;
}

// returns root of v's set
// path compression: every node on the path is pointed straight at the root
int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}

// true if a and b are already connected
bool same(int a, int b){
    return find(a) == find(b);
}

// merges sets of a and b; smaller set goes under the bigger one
// returns true if a merge happened, false if they were already connected
// (false => this edge closes a CYCLE in an undirected graph)
bool Union_bySize(int a, int b){

    a = find(a);
    b = find(b);

    if(a == b) return false;

    if(sz[a] < sz[b]) swap(a,b); // make 'a' the bigger set
    parent[b] = a;
    sz[a] += sz[b];

    comps--;               // two components became one
    mx = max(mx, sz[a]);   // largest component may have grown

    return true;
}

// same as above but attaches the shorter tree under the taller one
// use ONE union style per problem; by-size is the better default
bool Union_byRank(int a, int b){

    a = find(a);
    b = find(b);

    if(a == b) return false;

    if(rnk[a] < rnk[b]) swap(a,b); // make a the taller tree
    parent[b] = a;
    sz[a] += sz[b];
    if(rnk[a] == rnk[b]) rnk[a]++;

    comps--;
    mx = max(mx, sz[a]);

    return true;
}

/* =====================================================================
   DSU WITH PARITY  (bipartite check / "same team" vs "different team")
   ---------------------------------------------------------------------
   par[v]    : parent in this separate DSU
   parity[v] : colour of v RELATIVE to its parent (0 = same, 1 = different)
   After findp(v), parity[v] = colour of v relative to the ROOT.

   Use when: "a and b are enemies", "x and y must be in different groups",
             "is the graph still bipartite after adding this edge?"
   ===================================================================== */

int par[N], parity[N];

void initp(int n){
    for(int i = 1; i <= n; i++){
        par[i] = i;
        parity[i] = 0;
    }
}

int findp(int v){
    if(par[v] == v) return v;
    int root = findp(par[v]);        // compress the parent first
    parity[v] ^= parity[par[v]];     // then add parent's parity-to-root to ours
    return par[v] = root;            // finally point v at the root
}

// d = 0 : a and b must have the SAME colour
// d = 1 : a and b must have DIFFERENT colours (normal graph edge)
// returns false if the constraint contradicts earlier ones (=> not bipartite)
bool unite(int a, int b, int d){
    int ra = findp(a), rb = findp(b);

    if(ra == rb) return (parity[a] ^ parity[b]) == d; // already linked: just verify

    par[rb] = ra;
    parity[rb] = parity[a] ^ parity[b] ^ d; // chosen so a and b differ by exactly d
    return true;
}

/* =====================================================================
   KRUSKAL'S MST
   ---------------------------------------------------------------------
   Sort edges by weight, take every edge that joins two different sets.
   Returns total MST weight, or -1 if the graph is disconnected.
   Edge format: {w, u, v}
   ===================================================================== */

ll kruskal(int n, vector<array<ll,3>>& edges){
    init(n);
    sort(edges.begin(), edges.end()); // sorts by w first

    ll total = 0;
    for(auto& [w, u, v] : edges){
        if(Union_bySize(u, v)) total += w; // true => edge joined two sets
    }

    return comps == 1 ? total : -1;
}

/* =====================================================================
   PATTERNS — how to recognise and apply
   ---------------------------------------------------------------------
   1. "components / largest group after each edge"
        init(n); for each edge: Union_bySize(u,v); print comps, mx

   2. "is there a cycle" (undirected)
        if(!Union_bySize(u,v)) -> this edge closes a cycle

   3. "size of the group containing x"
        sz[find(x)]

   4. GRID connectivity (n rows, m cols)
        id(r,c) = r*m + c   (0-indexed) -> init with n*m nodes, 0..n*m-1
        union each open cell with its open right/down neighbour

   5. EDGE DELETIONS / "remove edges one by one"
        DSU cannot split sets -> read all queries offline,
        start from the graph with all deletions applied,
        process queries in REVERSE as additions, then reverse the answers

   6. MINIMUM SPANNING TREE / "connect all with minimum cost"
        kruskal(n, edges)

   7. BIPARTITE / two-team / enemy constraints
        initp(n); unite(a,b,1) for each "different" pair;
        a false return means impossible
   ===================================================================== */

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    init(n);

    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        Union_bySize(u, v);
    }

    cout << comps << " " << mx << "\n";

    return 0;
}