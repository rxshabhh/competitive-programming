#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,q; cin>>n>>q;
    ll a[n+1];
    ll pre[n+1];

    pre[1] = a[1];
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        pre[i] = pre[i-1]+a[i];
    }
    

    while(q--){
        ll a,b; cin>> a>>b;

        cout << pre[b]-pre[a-1]<<"\n";

    }

    return 0;
}