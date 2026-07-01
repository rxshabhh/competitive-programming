#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> a(n),b(n);
        for(auto &x : a) cin>>x;
        for(auto &x : b) cin >>x;

        bool ok = true;
        ll v =0;

        for(int i=0;i<n;i++){
            v += (a[i]-b[i]);

            if(v>0){
                ok = false;
                break;
            }

            
        }

        if(ok) cout <<"YES\n";
        else cout <<"NO\n";
    }

    return 0;
}