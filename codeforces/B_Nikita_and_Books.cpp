#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> a(n); for(auto &x : a) cin>>x;

        ll pre = 0;
        bool ok = true;

        for(ll i=0;i<n;i++){

            pre += a[i];

            ll k =i+1;
            ll sum = k*(k+1)/2;

            if(pre<sum){
                ok = false;
                break;
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}