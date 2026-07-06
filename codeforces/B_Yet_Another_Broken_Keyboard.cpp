#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    ll n,k; cin>>n>>k;

    string s; cin>>s;

    bool check[26] ={false};

    for(ll i=0;i<k;i++){
        char c; 
        cin>>c;

        check[c-'a'] = true;
    }

    vector<ll> dp(n+1);

    dp[0] = 0;
    ll ans =0;

    for(ll i=0;i<n;i++){


        if(check[s[i]-'a']) dp[i+1] = dp[i]+1;
        else dp[i+1]=0;

        ans += dp[i+1];

    }
    cout << ans;


    return 0;
}