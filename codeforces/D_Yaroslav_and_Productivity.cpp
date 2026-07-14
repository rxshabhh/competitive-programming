#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;
    while(t--){

        ll n,m; cin>>n>>m;
        vector<ll> a(n),b(m);

        for(auto &x : a) cin>>x;
        for(auto &x : b) cin>>x;

        sort(b.begin(),b.end());

        ll idx =0;

        
        ll mx =0;

        for(ll i=0;i<m;i++){

            ll curr =0;

            while(idx<b[i]){
                curr += a[idx];
                idx++;
            }

            mx += abs(curr);


        }

        ll sum= accumulate(a.begin()+idx,a.end(),0ll);

        cout << mx+sum << '\n';
        
    }

    return 0;
}