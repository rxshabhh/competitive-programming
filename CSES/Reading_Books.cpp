#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin>>n;
    vector<ll> a(n); for(auto &x : a) cin>>x;

    ll sum = accumulate(a.begin(),a.end(),0ll);

    ll mx = *max_element(a.begin(),a.end());

    cout << max(sum, mx*2);
    

    return 0;
}