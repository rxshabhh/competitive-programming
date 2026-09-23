#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+10;

int par[N], sz[N];


void make(int v){
    par[v]=v;
    sz[v]=1;
   
}

int find(int v){

    if(par[v]==v) return par[v];

    return par[v] = find(par[v]);
}




void Union(int a,int b){

    a= find(a);
    b=find(b);

    if(a!=b){
        par[a]=b;
        sz[b] += sz[a];
    }

}



int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin>>n>>q;

    for(int i=1;i<=n;i++){
        make(i);
    }



    while(q--){

        int op; cin>>op;

        if(op==1){
            int x,y; cin>>x>>y;

            Union(x,y);
        }

        else if(op==2){
            int a; cin>>a;
            int r = find(a);

            if(r!=a){
                par[r] = a;
                par[a] = a;
                sz[a]=sz[r];
            }
        }
        else{
            int b; cin>>b;
            cout << find(b) << "\n";
        }
    }


    return 0;
}