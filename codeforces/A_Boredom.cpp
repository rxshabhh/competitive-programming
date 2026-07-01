#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;cin>>n;
    vector<ll> a(n); for(auto &x : a) cin>>x;

    vector<ll> freq(100005,0);
    for(ll i=0;i<n;i++){
        freq[a[i]]++;
    }

    vector<ll> dp(100005,0);

    dp[1]=freq[1];

    for(ll i=2;i<=100000;i++){
        dp[i] = max(dp[i-1], dp[i-2]+ i*freq[i]);
    }

    cout << dp[100000];

    return 0;
}