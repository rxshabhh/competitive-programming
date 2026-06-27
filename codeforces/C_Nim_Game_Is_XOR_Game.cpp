#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod= 998244353;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;
    while(t--){
        ll n;cin>> n;
        vector<ll> a(n); for(auto &x : a) cin>>x;

        ll sum=0;
        ll cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]>0) cnt++;
            sum^=a[i];

        }

        if(cnt<2){
            cout << 0 << "\n";
            continue;
        }

        if(sum==0){
            cout << 1 <<'\n';
            continue;
        }

        ll ans=0;
        for(int i=0;i<n;i++){

            if((sum^a[i])<a[i]) ans++;
        }

        cout << ans%mod <<"\n";




    }

    return 0;
}