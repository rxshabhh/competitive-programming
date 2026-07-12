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

    vector<ll> div;

    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            div.push_back(i);
            if(i!=(n/i)){
                div.push_back(n/i);
            }
        }
    }



    for(ll x=1;x<div.size();x++){

        ll cnt=0;

        for(int i=1;i<=n;i+=div[x]){
            cnt += i;
        }

        res.insert(cnt);
        
    }

    ll sum = 1LL * (n*(n+1)/2);

    res.insert(sum);

    for(auto val : res){
        cout << val << " ";
    }
    cout << "\n";

    return 0;
}