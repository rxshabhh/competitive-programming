#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

void solve(){

    ll n,x,y; cin>>n >>x>>y;

    vector<ll> a(n); for(auto &x : a) cin>>x;

    ll cnt=0;

    map<pair<ll,ll>,ll> mpp;

    for(int i=0;i<n;i++){

        cnt += mpp[{(x-a[i] %x) %x, a[i]%y}];

        mpp[{a[i]%x, a[i]%y}]++;
    }



    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){

    //         if((a[i]+a[j]) %x==0 && (abs(a[i]-a[j]))%y ==0) cnt++;

    //     }
    // }

    cout << cnt << "\n";
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