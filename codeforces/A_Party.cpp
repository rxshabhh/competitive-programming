#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int mx =0;

vector<int> adj[2005];

void dfs(int curr_node, int curr_depth){

    mx = max(mx,curr_depth);

    for(auto child : adj[curr_node]){
        dfs(child,curr_depth+1);
    }


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    int N=n;
    vector<int> roots;


    for(int i=1;i<=n;i++){
        int x; cin>>x;

        if(x==-1){
            roots.push_back(i);
        }
        else{
            adj[x].push_back(i);
        }
    }

    for(auto root : roots){
        dfs(root,1);
    }

    cout << mx << "\n";

    



    return 0;
}