#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<vector<int>> adj;
//vector<bool> vis;
string s;
int cnt=0;

int dfs(int node){

    int balance = (s[node-1] =='W' ? 1 : -1);

    for(auto child : adj[node]){
        balance += dfs(child);
    }

    if(balance==0) cnt++;

    return balance;

    // vis[node] = true;
    
    // int w=0,b=0;

    // if(s[node-1] == 'W') w++;
    // else b++;
    
    // for(auto child : adj[node]){

    //     if(adj[node].size()>=2) continue;

    //     if(s[node-1]=='W' && s[child-1]=='B'){
    //         dfs(child,s);
    //         cnt++;
    //     }
    //     else if(s[node-1]=='B' && s[child-1]=='W') { dfs(child,s); cnt++;}

    
    // }

    // w=0,b=0;    
}

void solve(){

    int n; cin>>n;

    //adj.resize(n+1);
    adj.assign(n+1,vector<int>());
    cnt=0;

    for(int i=2;i<=n;i++){

        int x; cin>>x;
        adj[x].push_back(i);
    }

    cin>>s;

    dfs(1);

    cout << cnt << "\n";




    


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;

    while(t--){
        solve();
    }

    return 0;
}