#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){

    int n; cin>>n;
    vector<ll> pre(n+1,0);

    for(int i=1;i<=n;i++){
        ll x; cin>>x;

        pre[i] = pre[i-1] + x;

    }

    ll ans=0;

    for(int k=1;k<=n;k++){
        if(n%k) continue;

        ll mx = LLONG_MIN, mn = LLONG_MAX;

        for(int i=k;i<=n;i+=k){
            ll s =pre[i] - pre[i-k];

            mx = max(mx,s);
            mn = min(mn,s);

        }

        ans = max(ans,mx-mn);
    }

    cout << ans << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}