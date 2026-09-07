#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;

        vector<int> a(n); for(auto &x : a) cin>>x;

        vector<int> b(n); for(auto &x : b) cin>>x;
        
        int ans =0;

        int limit = min(n,k);

        int sum =0, maxb=0;

        for(int i=0;i<limit;i++){

            sum += a[i];
            maxb = max(maxb,b[i]);

            int left = k-(i+1);

            int curr = sum + (left*maxb);
            ans = max(ans,curr);
        }

        // if(2*n>k && k<n){
        //     ans += accumulate(a.begin(),a.end(),0);

        //     sort(b.begin(),b.end());
        //     for(int i=b.size()-1;i>=(n-k);i--){
        //         ans += b[i];
        //     }
        // }

        // else if(n>k){
        //     sort(a.begin(),a.end());

        //     for(int i=0;i<=k;i++){
        //         ans += a[i];
        //     }
        // }

        // else if(2*n<k){
        //     ans += accumulate(a.begin(),a.end(),0);
        //     ans += accumulate(b.begin(),b.end(),0);
        //     for(int i=0;i<(k-(2*n));i++){
        //         ans += b[i];
        //     }
        // }

        cout << ans << "\n";
    }

    return 0;
}