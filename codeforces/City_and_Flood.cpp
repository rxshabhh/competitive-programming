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

    int n,k; cin>>n>>k;

    for(int i=1;i<=n;i++){
        make(i);
    }

    while(k--){
        int a,b; cin>>a>>b;

        merge(a,b);
    }

    int cnt=0;
    for(int i=1;i<=n;i++){
        if(find(i)==i) cnt++;
    }

    cout << cnt;


    

    return 0;
}