#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        ll n; cin>>n;
        vector<ll> a(n); for(auto &x : a) cin>>x;

        sort(a.rbegin(),a.rend());

        ll sumx=0,sumy=0;

        for(int i=0;i<n;i++){
            if(sumx < sumy){
                sumx += (1LL<<a[i]);
            }
            else sumy += (1LL<<a[i]);
        }

        ll ans = sumx* sumy;
        cout << ans << "\n";
    }

    return 0;
}