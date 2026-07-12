#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

ll lcm(ll a, ll b){

    return a/__gcd(a,b)*b;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k; cin>>n>>k;
    vector<ll> a(n); for(auto &x : a) cin>>x;

    // bool ok = false;
    // for(auto val : a){
    //     if(val==k || (val%k==0 || k%val==0)){
    //         ok = true;
    //         break;
    //     }
    // }

    // if(ok) cout << "Yes";
    // else cout << "No";

    ll cnt =1;

    for(auto val : a){

        ll g = __gcd(val,k);

        cnt = lcm(cnt,g);

        if(cnt==k){
            cout << "Yes\n";
            return 0;
        }


    }

    cout << "No\n";

    return 0;
}