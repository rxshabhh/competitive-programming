#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// depending on the question, we might need to create a struct for returning an answer

struct SegTree {
    int size;
    vector<ll> tree;

    '''
        Neutral will be constant, range sum -> 0, range min-> LLONG_MAX, vice versa for range max, range gcd, xor -> 0
    
    '''
    const ll NEUTRAL = 0; 

    '''
        merge function for how you want to merge left and right children
        sum: left+right
        min: min(left,right), vice versa for max

    '''
    ll merge(ll left, ll right) {
        return left + right; 
    }

    // Initialize the tree with a size closest to the power of 2
    void init(int n) {
        size = 1;
        while (size < n) size *= 2; // may add 0s to the array to bring the size closest to the power of 2
        tree.assign(2 * size, NEUTRAL);
    }

    void build(vector<int>& a, int x, int lx, int rx) {
        if (rx - lx == 1) { // Leaf node (represents a single element)
            if (lx < a.size()) {
                tree[x] = a[lx]; // storing step
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

    void update(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) { // Reached the leaf node for index 'i'
            tree[x] = v;    // Change this if the update adds to the existing value (tree[x] += v)
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

    ll query(int l, int r, int x, int lx, int rx) {
        // Current segment [lx, rx) is completely OUTSIDE the query range [l, r)
        if (lx >= r || l >= rx) return NEUTRAL;

        // Current segment [lx, rx) is completely INSIDE the query range [l, r)
        if (lx >= l && rx <= r) return tree[x];

        // Current segment partially intersects the query range -> split and go deeper
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    SegTree st;
    st.init(n);


    vector<int> a(n); for (auto &x : a) cin >> x;
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