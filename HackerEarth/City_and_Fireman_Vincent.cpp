#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+10;

int par[N];
int sz[N];

void make(int v){
    par[v]=v;
    sz[v]=1;
}

int find(int v){

    if(par[v] == v) return v;
    
    return par[v] = find(par[v]);
}

void merge(int a,int b){

    a = find(a);
    b = find(b);

    if(a!=b){

        if(sz[a]<sz[b]) swap(a,b);
        par[b]=a;
        sz[a] += sz[b];
    }
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<int> eff(n+1);
    for(int i=1;i<=n;i++){
        cin>>eff[i];
    }

    for(int i=1;i<=n;i++){
        make(i);
    }

    int k; cin>>k;
    while(k--){
        int a,b; cin>>a>>b;

        merge(a,b);
    }

    vector<int> mn(n+1,INT_MAX), ways(n+1,0);

    for(int i=1;i<=n;i++){

        int r = find(i);
        if(eff[i]<mn[r]){
            mn[r] = eff[i];
            ways[r]=1;

        }

        else if(eff[i]==mn[r]) ways[r]++;
    }

    const int mod = 1e9+7;

    ll ans =1;
    for(int i=1;i<=n;i++){
        if(find(i)==i) ans = (ans*ways[i])%mod;
    }

    cout << ans;

    

    return 0;
}