#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
vector<string> grid;
vector<vector<bool>> vis;

int dr[] = {-1,1,0,0};
int dc[] = {0,0,1,-1};

bool isValid(int r, int c){

    if(r<0 || r>=n || c<0 || c>=m) return false;
    if(grid[r][c] == '#' || vis[r][c]) return false;

    return true;
}

void dfs(int r, int c){

    vis[r][c] = true;

    for(int i=0;i<4;i++){
        int nr = r +dr[i];
        int nc = c + dc[i];

        if(isValid(nr,nc)){
            dfs(nr,nc);
        }
    }

    
    
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;

    grid.resize(n);
    vis.assign(n,vector<bool>(m,false));

    for(int i=0;i<n;i++){
        cin >> grid[i];
    }

    int cnt =0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(grid[i][j] != '#' && vis[i][j] == false){
                dfs(i,j);
                cnt++;
            }
        }
    }

    cout << cnt << "\n";

    return 0;
}