#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[1010][100010];

// int func(int idx,int amt, vector<int>& h, vector<int>& s){
//     int n= h.size();

//     if(idx==n) return 0;
//     if(dp[idx][amt]!=-1) return dp[idx][amt];


//     int ans= 0;
//         // don't choose
//     ans = func(idx+1,amt,h,s);

//     // book choose
//     if(amt-h[idx]>=0){
//         ans = max(ans, func(idx+1,amt-h[idx],h,s)+s[idx]);
//     }



//     return dp[idx][amt] =ans;
    
    

// }

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // memset(dp,-1,sizeof(dp));


    

    int n,x; cin>>n>>x;
    vector<int> h(n),s(n);
    for(auto &x: h) cin>>x;
    for(auto &x: s) cin>>x;

    vector<int> dp(x+1,0);

    for(int i=0;i<n;i++){
        for(int j=x;j>=h[i];j--){
            dp[j] = max(dp[j], dp[j-h[i]]+s[i]);
        }
    }

    cout << dp[x];



    return 0;
}