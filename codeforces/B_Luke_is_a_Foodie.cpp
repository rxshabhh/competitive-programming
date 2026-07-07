#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        ll n,x; cin>>n>>x;
        vector<ll> a(n); for(auto &x : a) cin>>x;

        // v = upperbound --> failed
        // interval of vmin to vmax and count non-overlap pairs --> works 
        // i was tracking the overlap wrongly

        ll cmin = a[0]-x;
        ll cmx = a[0]+x;

        ll ans=0;

        for(int i=1;i<n;i++){

            ll nmin = a[i]-x;
            ll nmx = a[i]+x;

            cmin = max(cmin, nmin);
            cmx = min(cmx,nmx);

            if(cmin>cmx){
                ans++;

                cmin = nmin;
                cmx = nmx;
            }
            
        }

        cout << ans <<"\n";

        

    }

    return 0;
}