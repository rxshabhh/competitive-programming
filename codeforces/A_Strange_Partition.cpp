#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        vector<ll> a(n); for(auto &x : a) cin>>x;

        ll mini = 0, max=0;

        for(int i=0;i<n;i++){
            mini += (a[i]);

            max += (a[i]+x-1)/x;
        }

        cout << ((mini+x-1)/x) <<" " << max << endl;
         

    }

    return 0;
}