#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;cin>>n;
    vector<ll> a(n); for(auto &x :a ) cin>>x;

    ll pre=0,cnt=0;

    unordered_map<ll,ll> freq;
    freq[0]=1;

    
    for(ll i=0;i<n;i++){

        pre += a[i];

        ll key = ((pre%n) +n) % n;

        cnt += freq[key];
        freq[key]++;
    }

    cout << cnt;

    return 0;
}