#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[200010][2];



int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;

    while(t--){

        int n; cin>>n;
        string s; cin>>s;

        vector<int> x(n),y(n-1);

        for(auto &v : x) cin>>v;
        for(auto &v : y) cin>>v;

        dp[0][0] = (s[0]=='R' ?0 : -x[0]);
        dp[0][1] = (s[0]=='S' ? 0 : -x[0]);

        for(int i=1;i<n;i++){
            ll cr = (s[i]=='R'?0:-x[i]);
            ll cs = (s[i]=='S'?0:-x[i]);

            dp[i][0] = max(dp[i-1][0],dp[i-1][1]) + cr;
            dp[i][1] = max(dp[i-1][1]+cs,dp[i-1][0]+cs+y[i-1]);



        }

        cout << max(dp[n-1][0],dp[n-1][1]) << "\n";

    }

    return 0;
}