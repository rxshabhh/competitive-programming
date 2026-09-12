#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int mx =0;

vector<int> adj[2005];

void dfs(int node, int cnt){

    mx = max(mx,cnt);

    for(auto child : adj[node]){

        dfs(child,cnt+1);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> roots;

    int n; cin>>n;
    for(int i=1;i<=n;i++){

        int x; cin>>x;

        if(x==-1) roots.push_back(i);

        else adj[x].push_back(i);
    }

    for(auto val : roots){
        dfs(val,1);
    }

    cout << mx << "\n";



    

    return 0;
}