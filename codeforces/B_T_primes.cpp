#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int m = 1e6+10;

// ll cntdiv(ll n){

//     ll ans =1;
//     for(ll i=2;i*i<=n;i++){

//         int cnt =0;
//         while(n%i==0){
//             n/=i;
//             cnt++;

//         }
//         ans *= (cnt+1);
//     }

//     if(n>1) ans*=2;
//     return ans;
// }

vector<bool> isprime(m,true);


void sieve(){

    isprime[0] = isprime[1] = false;
    for(int i=2;i*i<=m;i++){

        if(isprime[i]){
            for(int j=i*i;j<m;j+=i){
                isprime[j] = false;
            }
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    // vector<string> res;

    // for(int i=0;i<n;i++){

    //     if(cntdiv(a[i]) == 3){
    //         res.push_back("YES");
    //     }

    //     else res.push_back("NO");
    // }

    // for(auto val : res){
    //     cout << val << "\n";
    // }

    sieve();

    while(n--){

        ll x; cin>>x;

        ll r = round(sqrt(x));

        if(r*r == x && isprime[r]){
            cout << "YES\n";
        }
        else cout << "NO\n";

    }

    



    return 0;
}