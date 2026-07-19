#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+5;

vector<int> adj[N+1];
int cat[N];
int valid=0;

void dfs(int node, int par, int streak, int m){

    if(cat[node]==1){
        streak++;
    }

    else streak=0;

    if(streak>m) return;

    bool is_leaf= true;

    for(auto child : adj[node]){
        if(child!=par){
            is_leaf=false;
            dfs(child,node,streak,m);
        }
    }

    if(is_leaf){
        valid++;
    }
}



int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin >> cat[i];
    }

    int t = n-1;
    while(t--){

        int x,y; cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);


    }

    dfs(1,0,0,m);

    cout<<valid<<"\n";




    

    return 0;
}