#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<ll> a(n); for(auto &x : a) cin>>x;

        ll c1 =0, c0 =0;

        for(int i=0;i<n;i++){
            if(a[i]==1) c1++;
            else if(a[i]==0) c0++;
        }

        cout << (c1 * (1LL<<c0)) << "\n";


    }

    return 0;
}