#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        ll n,k; cin>>n>>k;
        vector<ll> a(n*k); for(auto &x : a) cin>>x;

        ll i = n*k;

        ll sum = 0;

        while(k--){
            i -= (n/2 + 1);
            sum += a[i];



        }

        cout << sum << "\n";
    }

    return 0;
}