#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        string a,b; cin>>a>>b;

        int n= a.size();
        int m = b.size();

        vector<int> prea(n+1,0);

        for(int i=0;i<n;i++){
            prea[i+1] = (prea[i] + (a[i]-'0'))%10;
        }

        vector<int> preb(m+1,0);

        for(int i=0;i<m;i++){
            preb[i+1] = (preb[i] + (b[i]-'0'))%10;
        }



        vector<vector<int>> dp(n+1,vector<int>(m+1));

        dp[0][0] = 0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

                if(prea[i]==preb[j]){
                    dp[i][j] = dp[i-1][j-1]+1; 
                }


            }

                
        }

        cout << (prea.back() == preb.back() ? dp[n][m] : -1 )<< "\n";

        
 
    }

    return 0;
}