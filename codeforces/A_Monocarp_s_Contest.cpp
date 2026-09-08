#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        int c0=0;

        for(auto val : a){
            if(val==0){
                c0++;
            }
        }

        if(c0<2){
            cout << -1 << "\n";
        }

        else cout << a[0]+a[n-1] << "\n";

    }

    return 0;
}