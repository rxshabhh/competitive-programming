#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9+7;

ll dp[1000010];

ll func(ll sum,vector<ll> &v){

    if(sum==0) return 1;

    if(dp[sum]!=-1) return dp[sum];


    ll ans = 0;

    for(int c : v){
        if(sum-c>=0)ans = (ans + func(sum-c,v))%mod;
    }

    return dp[sum]=ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp,-1,sizeof(dp));
    
    ll n,x; cin>>n>>x;
    vector<ll> a(n); for(auto &x : a) cin>>x;

    ll res = func(x,a);
    cout << res%mod;



    return 0;
}