#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vector<ll> a(n); for(auto &x : a) cin>>x;

        ll ans = LLONG_MAX;

        
        
            

        for(int i=0;i<n;i++){
            ll need = (k-(a[i]%k))%k;
            ans = min(ans ,need);
        }

        if(k==4){
            ll cnt = 0;
            for(auto val : a){
                if(val%2==0) cnt++;
            }

            if(cnt>=2) ans = 0;
            else if(cnt==1) ans = min(ans,1LL);
            else ans = min(ans,2LL);
        }

        cout << ans << "\n";


    }


    

    return 0;
}