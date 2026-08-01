#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> adj;
vector<int> c;
vector<int> ans;

void dfs(int v){

    bool okay = (c[v]==1);

    for(auto child : adj[v]){

        // if(c[v]==1 && c[child]==1){
        //     // // remove v ??
        //     // adj[child] = adj[v];
        //     // ans.push_back(v);


        // }

        if(c[child]==0){
            okay = false;
        }

        dfs(child);
    }

    if(okay) ans.push_back(v);

    // multiple vertices with ci=0, then remove the smallest number
    // but in 3rd tc, they removed 5 instead of 1
    // and where to implement this logic
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    adj.resize(n+1);
    c.resize(n+1);

    

    int root = 0;

    for(int i=1;i<=n;i++){
        int pi, ci; cin>>pi>>ci;

        if(pi==-1) root = i;
        else{
            adj[pi].push_back(i);
        }
        c[i] = ci;
    }

    dfs(root);

    if(ans.size()==0) cout << -1 << "\n";
    else{
        sort(ans.begin(),ans.end());

        for(int val : ans){
            cout << val << " ";
        }
        cout << "\n";
    }

    

    return 0;
}