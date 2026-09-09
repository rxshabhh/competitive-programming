#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



void dfs(int vertex, int par,vector<vector<int>>& adj, set<int>& a, vector<int>& ans){

    int cnt = (a.count(vertex) ? 1 : 0);
    


    for(int child : adj[vertex]){
        if(child == par) continue;

    
        dfs(child,vertex,adj ,a,ans);

        cnt += ans[child];
    }

    ans[vertex] = cnt;



}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    int t; cin>>t;

    while(t--){
        
        int n; cin>>n;
        vector<int> p(n+1);

        vector<int> depth(n+1,0);
        p[1]=0;
        depth[1]=0;

        for(int i=2;i<=n;i++){
            cin >> p[i];
            depth[i] = depth[p[i]]+1;
        }

        int m; cin>>m;

        if(m==0){
            cout << 0 << "\n";
            continue;
        }

        vector<int> a(m); 
        bool has_root = false;

        for(int i=0;i<m;i++){
            cin >> a[i];
            if(a[i]==1) has_root = true;

        }

        int to_skip;

        if(has_root){
            to_skip = 1;
        }
        else{

            int mndepth = INT_MAX;

            int closest = -1;

            for(int v : a){

                if(depth[v] < mndepth){
                    mndepth  = depth[v];
                    closest = v;
                }
            }

            to_skip = closest;
        }


        cout << m-1 << " ";
        for(int i=0;i<m;i++){
            if(a[i]!=to_skip){
                cout << a[i] << " ";
            }
        }

        cout << "\n";
        // int n; cin>>n;
        // vector<int> p(n+1);

        // p[1] = 0;
        // for(int i=2;i<=n;i++){
        //     cin >> p[i];
        // }



        // int m; cin>>m;
        // vector<int> a(m); for(auto &x : a) cin>>x;


        // vector<vector<int>> adj(n);

        // for(int i=1;i<n;i++){
        //     int u = i;
        //     int v = p[i];

        //     adj[u].push_back(v);
        //     adj[v].push_back(u);



        // }

        // set<int> v;
        // for(auto val : a) v.insert(val);

        // vector<int> ans(n,0);

        // dfs(1,0,adj,v,ans);

        // for(int i=0;i<m;i++){
        //     cout << ans[a[i]] << " ";
        // }

        // cout << "\n";


    }

    return 0;
}