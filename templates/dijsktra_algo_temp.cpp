#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+10;
const int INF = 1e9+10;

vector<pair<int,int>> g(N);  // for storing weighted graph always use this

vector<int> vis(N,0), dist(N,INF);

void dijsktra(int source){  // shortest distance from a source

    set<pair<int,int>> st; // first is weight, n second is node. wt is first for sorting purpose

    st.insert({0,source});

    dist[source] = 0;
     

    while(st.size()>0){

        auto node = *st.begin; // minimum element from set st
        int v = node.second;
        int d = node.first;

        st.erase(st.begin());
        
        if(vis[v]) continue;
        vis[v]=1;

        // go to all the childs of node v
        for(auto child : g[v]){

            int child_v = child.first;
            int wt = child.second;

            if(dist[v]+wt < dist[child_v]){
                dist[child_v] = dist[v]+wt;
                st.insert({child_v,dist[child_v]});
            }
        }
    }





}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // standard input approach

    int n,m; cin>>n>>m;  // n-->vertices, m-->edges

    for(int i=0;i<m;i++){
        int x,y,wt; cin>>x>>y>>wt;

        g[x].push_back({y,wt});  // x connected to y with weight wt
    }

    

    return 0;
}