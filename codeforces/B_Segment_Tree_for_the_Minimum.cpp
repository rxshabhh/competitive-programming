#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct SegTree {
    int size;
    vector<ll> tree;

    // ==========================================
    // STEP 1: Define the NEUTRAL ELEMENT
    // ==========================================
    // This is the value that doesn't change the result of your operation.
    // - For Range Sum: 0
    // - For Range Min: LLONG_MAX
    // - For Range Max: LLONG_MIN
    // - For Range GCD: 0
    // - For Range XOR: 0
    const ll NEUTRAL = LLONG_MAX; 

    // ==========================================
    // STEP 2: Define the MERGE FUNCTION
    // ==========================================
    // How do you combine the left and right children?
    // - For Sum: return left + right;
    // - For Min: return min(left, right);
    // - For Max: return max(left, right);
    ll merge(ll left, ll right) {
        return min(left,right);
    }
    // ==========================================

    // Initialize the tree with a size that is a power of 2
    void init(int n) {
        size = 1;
        while (size < n) size *= 2; // Padding to the next power of 2
        tree.assign(2 * size, NEUTRAL);
    }

    // Recursive build: O(N) time complexity
    void build(vector<int>& a, int x, int lx, int rx) {
        if (rx - lx == 1) { // Leaf node (represents a single element)
            if (lx < a.size()) {
                tree[x] = a[lx]; // STEP 3: You might need to change how a single element is stored
            }
            return;
        }

        int m = lx + (rx - lx) / 2;
        build(a, 2 * x + 1, lx, m);      // Build left child
        build(a, 2 * x + 2, m, rx);      // Build right child

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]); // Merge children
    }

    void build(vector<int>& a) {
        build(a, 0, 0, size);
    }

    // Point Update: O(log N) time complexity
    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) { // Reached the leaf node for index 'i'
            tree[x] = v;    // STEP 4: Change this if the update adds to the existing value (tree[x] += v)
            return;
        }

        int m = lx + (rx - lx) / 2;
        if (i < m) {
            update(i, v, 2 * x + 1, lx, m); // Go left
        } else {
            update(i, v, 2 * x + 2, m, rx); // Go right
        }

        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]); // Update current node after children update
    }

    void update(int i, int v) {
        update(i, v, 0, 0, size);
    }

    // Range Query: O(log N) time complexity
    // We are looking for the answer in the range [l, r)
    ll query(int l, int r, int x, int lx, int rx) {
        // 1. Current segment [lx, rx) is completely OUTSIDE the query range [l, r)
        if (lx >= r || l >= rx) return NEUTRAL;

        // 2. Current segment [lx, rx) is completely INSIDE the query range [l, r)
        if (lx >= l && rx <= r) return tree[x];

        // 3. Current segment partially intersects the query range -> split and go deeper
        int m = lx + (rx - lx) / 2;
        ll left_result = query(l, r, 2 * x + 1, lx, m);
        ll right_result = query(l, r, 2 * x + 2, m, rx);

        return merge(left_result, right_result);
    }

    ll query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin >> n >> m;

    SegTree st;
    st.init(n);

    // O(N) Initialization
    vector<int> a(n); 
    for (auto &x : a) cin >> x;
    st.build(a);

    // Process Queries
    while (m--) {
        int op; 
        cin >> op;

        if (op == 1) {
            int i, v; 
            cin >> i >> v;
            // i is 0-indexed in this implementation
            st.update(i, v); 
        } else {
            int l, r; 
            cin >> l >> r;
            // query is [l, r) meaning 'l' is included, 'r' is excluded
            cout << st.query(l, r) << "\n"; 
        }
    }

    return 0;
}