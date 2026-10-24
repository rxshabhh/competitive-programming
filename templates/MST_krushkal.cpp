#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5+10;

int parent[N];
int sz[N];

void make(int i){
    par[i]=i;
    sz[i]=1;
}

int find(int v){

    if(par[v]==v) return v;
    return par[v] = find(par[v]);
}

void UnionSize(int x, int y){

    int r1 = find(x), r2=find(y);

    if(r1!=r2){

        if(sz[r1]<sz[r2]) swap(r1,r2);

        sz[r1]+=sz[r2];
        par[r2]=r1;
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;

    vector<pair<int,pair<int,int>>> edges;  // wt : {u,v}

    // take inputs

    int total = 0;

    sort(edges.begin(),edges.end());

    for(int i=1;i<=n;i++) make(i);

    for(auto &edge : edges){

        int wt = edge.first;
        auto [u,v] = edge.second;

        if(find(u)==find(v)) continue;

        UnionSize(u,v);
        total+=wt;
    }

    // total will return the minimum spanning tree sum

    


    return 0;
}