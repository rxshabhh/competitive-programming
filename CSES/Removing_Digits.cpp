#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[1000010];

int func(int i){

    if(i==0) return 0;
    
    if(dp[i]!=-1) return dp[i];

    // dp[i] is the minimum steps to reduce i to 0
    
    string s = to_string(i);
    int ans =INT_MAX;
    for(int x=s.size()-1;x>=0;x--){

        if(s[x]-'0' != 0) ans = min(ans,1+func(i-(s[x]-'0')));
    }

    return dp[i] =ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin>>n;
    memset(dp,-1,sizeof(dp));

    cout << func(n);
    


    return 0;
}