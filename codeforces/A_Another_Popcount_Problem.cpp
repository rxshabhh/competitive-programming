#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;

        ll mx=0;
        ll cnt=1;

        while(n>=cnt){
            ll x = min(k, n/cnt);
            if(x==0) break;
            mx += x;
            n -= x*cnt;
            cnt *=2;
        }

        cout << mx <<'\n';
    }

    return 0;
}