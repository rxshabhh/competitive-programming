#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

ll dp[100010][2];

ll func(ll n, ll curr){


    if(dp[n][curr]!=-1) return dp[n][curr];
    if(curr==1){
        if(n==0) return 1;
        else return dp[n][curr] = 3*func(n-1,0)%mod;
    } // top
    // bottom
    else{
        if(n==0) return 0;
        else return dp[n][curr] = (2*func(n-1,0)+ func(n-1,1))%mod;
    }
    
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp,-1,sizeof(dp));
    ll n; cin>>n;

    cout << func(n,1);

    return 0;
}