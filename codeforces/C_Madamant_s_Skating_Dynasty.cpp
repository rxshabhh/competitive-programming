#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;

// Brute force

// int cnt = 0;

// void func(int node, int curr_cost, vector<int>& a){
//     int n = a.size();

//     if(node==n-1){
//         cnt =(cnt+curr_cost) % mod;
//         return;
//     }
//     for(int i =n-1;i> node; i--){
//         int cost =(a[i] -a[node]) % mod;
//         int c =(cost+ curr_cost) % mod;

//         func(node+1,c,a);
//     }
// }
ll power(ll base, ll e){

    ll res=1;
    base %= mod;
    while(e>0){

        if(e%2==1) res = (res*base)%mod;
        base = (base*base)%mod;
        e/=2;
    }

    return res;
}

ll modinv(ll n){

    return power(n,mod-2);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;

    while(t--){

        int n; cin >> n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        if(n==1){
            cout << 0 << "\n";
            continue;
        }
        
        

        sort(a.begin(), a.end());

        ll cnt =1;
        for(int i=1;i<=n-1;i++){

            cnt = (cnt*i) % mod;
        }

        vector<ll> suff(n+1,0);

        for(int i=n-1;i>=0;i--){
            suff[i] = (suff[i+1]+a[i])%mod;
        }

        ll ans =0;

        for(int i=0;i<n-1;i++){

            ll choice = n-i-1;

            ll sum = suff[i+1];
            ll cost = (sum - (choice *a[i]) %mod +mod)%mod;

            ll div = (cnt* modinv(choice)) %mod;

            ll t = (cost * div)%mod;

            ans = (ans + t)%mod;
        }
        
        // func(0,0,a); 

        // cout << cnt << "\n";

        cout << ans << "\n";
    }

    return 0;
}