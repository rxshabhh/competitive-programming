#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;
    while(t--){
        int n;cin>>n;

        ll ans =0;

        for(int b=1;b<=n;b++){
            ll k = n/b;
            ans += k*k;
        }

        cout << ans <<'\n';
    }

    return 0;
}