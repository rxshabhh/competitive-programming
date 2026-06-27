#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244352;
const ll mx = 998244353;

ll p(ll base, ll expo){
    ll res=1;
    base %= mx;
    while(expo>0){
        if(expo%2==1) res= (res*base)%mx;
        base = (base*base)%mx;
        expo/=2;

    }

    return res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        ll n,m,r,c; cin>>n>>m>>r>>c;

        ll cnt  = ((n%mod)*(m%mod))%mod;
        ll ce = (((n-r+1)%mod)*((m-c+1)%mod))%mod;

        ll k = (cnt-ce+mod)%mod;
        cout << p(2,k) <<'\n';
    }

    return 0;
}