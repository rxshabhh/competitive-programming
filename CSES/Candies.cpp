#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9+7;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k; cin>>n>>k;


    vector<ll> a(n); for(auto &x :a) cin>>x;

    vector<vector<ll>> dp(n+1, vector<ll>(k+1,0));

    dp[0][0]=1;

    for(int i=1;i<=n;i++){

        vector<ll> pre(k+1,0);
        pre[0] = dp[i-1][0];

        for(int j=1;j<=k;j++){
            pre[j] = (pre[j-1] + dp[i-1][j])%mod;
        }

        for(int j=0;j<=k;j++){

            ll l = j-a[i-1]-1;
            dp[i][j] = pre[j];

            if(l>=0) dp[i][j] = (dp[i][j] - pre[l] + mod)%mod;
        }
    }

    cout << dp[n][k];



    return 0;
}