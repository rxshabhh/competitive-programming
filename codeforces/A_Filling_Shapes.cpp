#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[66];

ll func(ll i){



    if(i%2!=0) return 0;
    if(i==0) return 1;

    if(dp[i]!=-1) return dp[i];
    
    ll ans = func(i-2)*2;


    return dp[i]=ans;
}

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin>>n;
    memset(dp,-1,sizeof(dp));

    cout << func(n);

    // solution 2: 1LL << (n/2) as for even number it is 2^(n/2)


    return 0;
}