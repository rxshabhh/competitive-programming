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

        sort(a.begin(),a.end());

        ll g = a[0];

        bool ok = true;
        for(int i=n-1;i>=2;i--){
           if(a[i]%a[i-1] != a[i-2]){
                ok = false;
                break;
           }
        }

        if(ok){
            cout << a[n-1] << " " << a[n-2] <<"\n";
        }
        else cout << -1 <<"\n";
    }

    return 0;
}