#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<vector<int>> grid(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }

    int rows =0, cols=0;

    for(int i=0;i<n;i++){

        int sum[2]{};
        for(int j=0;j<n;j++){
            sum[j%2] += grid[i][j];
        }

        rows += max(sum[0],sum[1]);

    }

    for(int i=0;i<n;i++){
        int sum[2]{};

        for(int j=0;j<n;j++){
            sum[j%2] += grid[j][i];
        }

        cols += max(sum[0],sum[1]);
    }

    cout << max(rows,cols);

    return 0;
}