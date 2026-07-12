#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


ll solve(ll x, ll y){

    ll cnt =0;

    for(ll i=1;i<=x;i++){
        for(ll j=1;j<=y;j++){
            
            if(floor(i/j)==(i%j)) cnt++;
        }
    }

    return cnt;

    // cnt the pairs of co-primes such that a<=x and b<=y
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;

    while(t--){
        ll x,y; cin>>x>>y;

        cout << solve(x,y) << "\n";
    }

    return 0;
}