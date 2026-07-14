#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;

    while(t--){
        int n; cin >>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        vector<int> dp(n,0);
        
        int mx =0;
        for(int i=0;i<n;i++){
            dp[i]=a[i];

            for(int j=0;j<i;j++){
                if(i-j>a[i] && i-j>a[j]){
                    dp[i] = max(dp[i],dp[j]+a[i]);
                }
            }

            mx = max(mx,dp[i]);
        }

        cout << mx << "\n";

        
    }

    

    return 0;
}