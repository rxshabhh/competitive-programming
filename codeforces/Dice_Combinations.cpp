#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mod = 1e9+7;
int dp[1000010];

int func(int i){

    if(i==0) return 1;
    if(i<0) return 0;
    if(dp[i]!=-1) return dp[i];

    ll ans=0;
    for(int x=1;x<=6;x++){
        ans = (ans+func(i-x))%mod;
    }

    return dp[i]=ans;


}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp,-1,sizeof(dp));
    int n; cin>>n;

    cout << func(n)%mod;



    return 0;
}