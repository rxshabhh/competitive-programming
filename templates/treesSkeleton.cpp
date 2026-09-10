#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5+10;  // max value to store

vector<int> adj[N];
bool vis[N];


void dfs(int vertex){

    // after entering vertex
    vis[vertex] = 1;

    for(int child  : adj[vertex]){
        // before entering vertex's child

        if(vis[child]) continue;

        dfs(child);
        // returning back from child
    }

    // returning back from vertex
}

// In_time and out_time

map<int,pair<int,int>> time_tree;  // key : {in time, out time}
int t=0;

void dfs(int vertex){

    // after entering vertex

    t++;
    time_tree[vertex].first = t;
    vis[vertex] = 1;

    for(int child  : adj[vertex]){
        // before entering vertex's child

        if(vis[child]) continue;

        dfs(child);
        // returning back from child
    }

    // returning back from vertex
    time_tree[vertex].second = t;
    t++;
}

// Level printing using DFS i.e number of level = height of the tree
void dfs(int vertex, vector<int>& level, int l=0){

    // after entering vertex
    vis[vertex] = 1;

    level[vertex] = l;

    for(int child  : adj[vertex]){
        // before entering vertex's child

        if(vis[child]) continue;

        dfs(child,level,l+1);
        // returning back from child
    }

    // returning back from vertex
}

// BFS

void bfs(int root){

    queue<pair<int,int>> q;

    // {node : parent}
    q.push({1,0}); // root and child
    
    while(q.empty()==false){
        int node = q.front().first;
        // now we have node
        int parent = q.front().second;
        //now we have parent too

        q.pop();

        for(auto child : adj[node]){
            if(child == parent) continue;
            q.push({child,node});
        }
    }

}

// Level using BFS
void bfs(int root){

    queue<pair<int,int>> q;

    // {node : parent}
    q.push({1,0}); // root and child
    int level = 0;

    // each time in a queue we have level x and level x+1 only
    
    while(q.empty()==false){

        int k= q.size();

        for(int i=0;i<k;i++){
            int node = q.front().first;
            // now we have node
            int parent = q.front().second;
            //now we have parent too

            q.pop();

            for(auto child : adj[node]){
                if(child == parent) continue;
                q.push({child,node});
            }
        }
        level++; 
    }

}



void solve(){

    // for getting height 

    vector<int> level(n+1,0);
    int ans=0;
    dfs(1,0,level);
    for(int i=1;i<=n;i++){
        ans = max(ans, level[i]+1);
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}