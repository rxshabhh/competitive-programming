#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[1000010];

int func(int sum, vector<int> &v){
    int n=v.size();

    if(sum==0) return 0;
    
    if(dp[sum] != -1) return dp[sum];
    
    int ans=1e9;
    for(int i=0;i<n;i++){
       if(sum-v[i] >=0) ans = min(ans,1+func(sum-v[i],v));
        
    }

    return dp[sum]=ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp,-1,sizeof(dp));

    ll n,x; cin>>n>>x;

    vector<int> coins(n); for(auto &x : coins) cin>>x;

    int res= func(x,coins);
    if(res==1e9) cout << -1;
    else cout<< res;



    return 0;
}