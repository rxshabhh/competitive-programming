#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9+7;

int dp[1010][1010];

int func(int i, int j, vector<string> &m,int n){

    
    if(i>=n || j>=n) return 0; // 
    if(m[i][j]=='*') return 0; // 

    if(i==n-1 && j==n-1) return 1;

    if(dp[i][j]!=-1) return dp[i][j];
    
    int ans=0;
    // dp[i][j] means the number of paths from i,j to n,n

    ans = (ans+ func(i+1,j,m,n))%mod;
    ans= (ans+ func(i,j+1,m,n))%mod;

    return dp[i][j]=ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp,-1,sizeof(dp));

    int n; cin>>n;
    vector<string> m(n);

    for(auto &x :m) cin>>x;


    cout << func(0,0,m,n); //






    

    return 0;
}