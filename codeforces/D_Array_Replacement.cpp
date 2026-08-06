#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define int ll

int32_t main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        int n; cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        vector<int> diff(n);

        for(int i=1;i<n;i++){
            diff[i] = a[i]-a[i-1];
        }

        int l=1;
        while(l<n){
            int r=l;
            while(r<n && abs(diff[l]%2) == abs(diff[r]%2)) r++;

            sort(diff.begin()+l,diff.begin()+r);
            l=r;
        }

        vector<int> ans(n);
        ans[0]=a[0];
        for(int i=1;i<n;++i){

            ans[i] = ans[i-1]+diff[i];
        }

        for(int i=0;i<n;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        
    }

    return 0;
}