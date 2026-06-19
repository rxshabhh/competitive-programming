#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int n,k,q; cin>>n>>k>>q;
        vector<int> a(n); for(auto &x :a ) cin>>x;

        ll ans=0;
        ll len=0;

        for(int i=0;i<n;i++){
            if(a[i]<=q) len++;

            else{
                if(len>=k){
                    ll x = len-k+1;
                    ans += x*(x+1) / 2;

                }

                len =0;
            }
        }

        if(len>=k){
            ll x = len-k+1;
            ans += x*(x+1)/2;
        }

        cout << ans << "\n";
    }

    return 0;
}