#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[100005];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

    
        int n;cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }

        fill(dp,dp+n+1,1);

        for(int i=2;i<=n;i++){
        
            for(int j=1;j*j<=i;j++){
                if(i%j != 0) continue;

                if(a[j]<a[i]) dp[i] = max(dp[i],1+dp[j]);
                if((i/j)!=j && a[i/j] < a[i]) dp[i]=max(dp[i],1+dp[i/j]);
            }
        }

        cout << *max_element(dp,dp+n+1) << "\n";

    }




    return 0;
}