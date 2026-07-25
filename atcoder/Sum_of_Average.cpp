#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll m = 998244353;


ll power(ll base, ll exp) {
    ll res = 1;
    base %= m;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) %m;
        base = (base * base) %m;
        exp /= 2;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, m - 2);
}

ll func(ll l, ll r, vector<ll>& pre){

    return (pre[r]-pre[l-1]+m)%m;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    ll n; cin>>n;
    vector<ll> a(n+1); 

    vector<ll> pre(n+1,0);

    for(ll i=1;i<=n;i++){

        cin>>a[i];
        pre[i] = (pre[i-1]+a[i])%m;
    }

    ll ans =0;
    ll sum=0;

    for(ll i=1;i<=n;i++){
        
        if(i==1){
            sum = func(1,n,pre);
        }
        else{

            if(i<=n-i+1){
                sum = (sum + func(i,n-i+1,pre))%m;
            }
            else sum = (sum - func(n-i+2,i-1,pre) + m) % m;
        }

        ll cur = (sum * modInverse(i)) % m;
        ans = (ans+cur) % m;
    }

    cout << ans << "\n";





    

    return 0;
}