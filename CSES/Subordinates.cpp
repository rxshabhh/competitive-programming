#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// vector<int> adj;
vector<vector<int>> adj;
vector<int> ans;


int dfs(int vertex){
    int cnt =0;

    for(auto child : adj[vertex]){
        cnt += 1 + dfs(child);
    }

    ans[vertex] = cnt;
    return cnt;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    adj.resize(n+1);
    ans.resize(n+1);

    for(int i=2;i<=n;i++){
        int x; cin>>x;
        adj[x].push_back(i);
    }

    dfs(1);

    for(int i=1;i<=n;i++){
        cout << ans[i] << " ";
    }


    

    return 0;
}