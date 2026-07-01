#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        ll n;cin>>n;
        vector<ll> a(n); for(auto &x : a) cin>>x;

        ll ans=0;

        stack<ll> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && a[i]%a[s.top()]>0){

                ans += 1ll * (n-i) * min(a[i]%a[s.top()], a[s.top()] -a[i] % a[s.top()]);
                s.pop();
            }
            s.push(i);
        }
        cout << ans <<"\n";

    }

    return 0;
}