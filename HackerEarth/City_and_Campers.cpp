#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+10;

int par[N], sz[N];
multiset<int> sizes;

void make(int v){
    par[v]=v;
    sz[v]=1;
    sizes.insert(1);
}

int find(int v){

    if(par[v]==v) return par[v];

    return par[v] = find(par[v]);
}

bool same(int a, int b){

    if(find(a)==find(b)) return true;
    
    return false;
}

void merge(int a,int b){

    sizes.erase(sizes.find(sz[a]));
    sizes.erase(sizes.find(sz[b]));

    sizes.insert(sz[a]+sz[b]);

}

void Union(int a,int b){

    a= find(a);
    b=find(b);

    if(!same(a,b)){

        if(sz[a]<sz[b]){
            swap(a,b);
        }

        par[b] = a;
        merge(a,b);
        sz[a] += sz[b];
    }

}



int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin>>n>>q;

    for(int i=1;i<=n;i++){
        make(i);
    }

    //int diff =0;

    while(q--){

        int x,y; cin>>x>>y;

        



        if(!same(x,y)) Union(x,y);

        if(sizes.size()==1) cout << 0 << "\n";

        else {
            int mn = *(sizes.begin());
            int mx = *(--sizes.end());
            cout << mx-mn << "\n";
        }


        

        // int mx = 0, mn=INT_MAX;

        // for(int i=1;i<=n;i++){
        //     if(find(i)==i){
        //         mx = max(mx,sz[i]);
        //         mn = min(mn,sz[i]);
        //     }
        // }

        // cout << mx-mn << "\n";
    }


    return 0;
}