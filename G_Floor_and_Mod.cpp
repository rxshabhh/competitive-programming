#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


// ll solve(ll x, ll y){

//     ll cnt =0;

//     for(ll i=1;i<=x;i++){
//         for(ll j=1;j<=y;j++){
            
//             if(floor(i/j)==(i%j)) cnt++;
//         }
//     }

//     return cnt;

//     // cnt the pairs of co-primes such that a<=x and b<=y
// }


/*
    I thought for co-prime logic but look at the cases where k =2 or 3... or so on
    it will be valid for k=1, and there we odn't need spf, every altenate number is co-prime
*/
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;

    while(t--){
        ll x,y; cin>>x>>y;

        ll ans =0;

        for(int i=1;i*i<x;i++){
            ans += max(0ll, min(y,x/i -1)-i);
        }

        cout << ans << '\n';
    }

    return 0;
}