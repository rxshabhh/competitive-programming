#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,x; cin>>n>>x;
    vector<ll> a(n); for(auto &x : a) cin>>x;

    map<ll,ll> freq;
    freq[0]=1;

    ll pre=0,cnt=0;

    for(ll i=0;i<n;i++){
        pre += a[i];
        
        cnt += freq[pre-x];
        freq[pre]++;
    }

    cout << cnt;

    return 0;
}