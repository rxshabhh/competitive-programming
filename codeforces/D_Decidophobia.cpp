#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int n,d; cin>>n>>d;

        vector<ll> sum(3*n+1,0), val(n+1);
        vector<ll> a(n); for(auto &x : a) cin>>x;

        vector<ll> b(3*n);
        for(int i=0;i<3*n;i++){
            b[i] = a[i%n];


        }

        sum[0]=0;
        for(int i=1;i<3*n;i++){
            sum[i] = sum[i-1]+b[i-1];

        }

        for(int i=n;i<=2*n;i++){
            val[i-n] = 1ll * ((d<<1)+1)*b[i-1] - (sum[i+d]-sum[i-d-1]);
        }

        ll ans=0;
        for(int i=1;i<=n;i++){
            ans += max(0ll,val[i]);

        }

        cout << ans <<'\n';


    }

    return 0;
}