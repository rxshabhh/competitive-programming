#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// int func(int n){

//     int res = 1;
//     while(res<n){
//         res *= 2;

//     }
//     return res;
// }

void solve(){

    int n; ll k; cin>>n>>k;

    vector<int> a(n); for(auto &x : a) cin>>x;

    ll res =0;

    for(int b=30;b>=0;b--){

        int cnt =0;
        for(int i=0;i<n;i++){

            if(!(a[i]>>b&1)) cnt++;
        }

        if(cnt<=k){
            k -= cnt;
            res |= (1<<b);
        }
    }

    cout << res << "\n";

    // int cnt=0;

    // for(int i=0;i<n;i++){

    //     if(((a[i]-1)&a[i]) && (cnt<=k)){

    //         a[i] = func(a[i]);
    //         cnt++;

    //     }

    // }

    // int res = a[0];
    // for(int i=1;i<n;i++){
    //     res = (res & a[i]);
    // }

    // cout << res << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        solve();
    }

    

    return 0;
}