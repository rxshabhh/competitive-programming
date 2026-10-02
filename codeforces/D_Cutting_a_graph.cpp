#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+5;

int parent[N], sz[N], rnk[N];
int comps, mx; // live component count and largest size
void make(int v){ parent[v] = v; sz[v] = 1; rnk[v] = 0; }
void init(int n){ for(int i = 1; i <= n; i++) make(i); comps = n; mx = 1; }
int find(int v){
 if(v == parent[v]) return v;
 return parent[v] = find(parent[v]); // path compression
}
bool same(int a, int b){ return find(a) == find(b); }
bool Union_bySize(int a, int b){
 a = find(a); b = find(b);
 if(a == b) return false;
 if(sz[a] < sz[b]) swap(a, b);
 parent[b] = a; sz[a] += sz[b];
 comps--; mx = max(mx, sz[a]);
 return true;
}

struct Queries{
    string type;
    int u,v;
};


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k; cin>>n>>m>>k;

    init(n);

    while(m--){
        int u,v; cin>>u>>v;

    
    }

    vector<string> ans;

    vector<Queries> q(k);

    
    for(int i=0;i<k;i++){
        cin>>q[i].type>>q[i].u>>q[i].v;
    }

    for(int i=k-1;i>=0;i--){

        if(q[i].type == "ask"){
            if(same(q[i].u,q[i].v) ) ans.push_back("YES");
            else ans.push_back("NO");
        }

        else if(q[i].type  == "cut"){

            Union_bySize(q[i].u, q[i].v);
        }
    }

    for(int i=ans.size()-1;i>=0;i--){
        cout << ans[i] << "\n";
    }
    

    return 0;
}