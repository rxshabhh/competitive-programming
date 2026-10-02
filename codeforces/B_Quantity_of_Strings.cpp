#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9+7;

const int N=2005;

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

ll pw(ll a,int e,int m=mod){ 
    ll r=1%m; 
    a%=m; 
    for(;e;e>>=1,a=a*a%m) 
    if(e&1) r=r*a%m; 
    return r;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,k; cin>>n>>m>>k;

    comps = n;
    init(n);

    for(int i=1;i<=n-k+1;i++){

        for(int j=0;j<(k/2);j++){
            Union_bySize(i+j,i+k-1-j);
        }
    }

    cout << pw(m,comps);

    

    return 0;
}