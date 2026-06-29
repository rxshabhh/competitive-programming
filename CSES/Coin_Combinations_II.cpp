#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9+7;

int dp[100010];



int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,x; cin>>n>>x;
    vector<int> coins(n); for(auto &x : coins) cin>>x;

    vector<int> dp(x+1,0);
    dp[0]=1;

    for(int c : coins){
        for(int s=c;s<=x;s++){
            dp[s] = (dp[s]+dp[s-c])%mod;
        }
    }

    cout << dp[x]%mod;

    return 0;
}