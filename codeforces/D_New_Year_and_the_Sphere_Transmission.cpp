#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin>>n;

    set<ll> res;

    // ll sum = 1ll*(n*(n+1)/2);

    // for(ll k=1;k<=n;k++){

    //     if(n%k) continue;

    //     if(k==1 || k== (n-1)){
    //         res.insert(sum);   
    //     }

    //     else if(k==n){
    //         res.insert(1);
    //     }
    //     else{

    //         ll cnt =0;

    //         for(ll m=1;m<=n;m+=k){
    //             cnt += m;
    //         }

    //         res.insert(cnt);
    //     }
    // }

    // TLE on test case 4


    //    for(ll k=1;k<=n;k++){

    //        if(n%k) continue;

    //        ll cnt=0;

    //        for(int j=1;j<=n;j+=k){
    //         cnt+= j;
    //        }

    //        res.insert(cnt);


    //    }


    // tle on 19th test case

    // vector<ll> div;

    for(ll i=1;i*i<=n;i++){
        if(n%i==0){

            ll d1=i;
            ll m1 = n/d1;

            ll sum1 = m1*(2+(m1-1)*d1)/2;
            res.insert(sum1);

            ll d2 = n/i;

            ll m2 = n/d2;

            ll sum2 = m2*(2+(m2-1)*d2)/2;
            res.insert(sum2);
        }
    }



    // for(ll x=1;x<div.size();x++){  // this loop increases the time complexity

    //     ll cnt=0;

    //     for(int i=1;i<=n;i+=div[x]){
    //         cnt += i;
    //     }

    //     res.insert(cnt);
        
    // }

    // ll sum = 1LL * (n*(n+1)/2);

    // res.insert(sum);

    for(auto val : res){
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}