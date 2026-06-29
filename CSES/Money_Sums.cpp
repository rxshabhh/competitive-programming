#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[105][100010];

bool func(int idx, int sum, vector<int>& a){
    // 
    if(idx<0) return (sum==0);
    if(dp[idx][sum] != -1) return dp[idx][sum];


    bool ans = false;

    if(sum-a[idx]>=0) ans |= func(idx-1,sum-a[idx],a);
    ans |= func(idx-1,sum,a);

    return dp[idx][sum] = ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp,-1,sizeof(dp));

    int n;cin>>n;
    vector<int> coins(n); for(auto &x : coins) cin>>x;

    int mx = accumulate(coins.begin(), coins.end(),0);
    int mini = *min_element(coins.begin(),coins.end());

    vector<int> res;
    for(int i=mini; i<=mx;i++){
        if(func(n-1,i,coins)) res.push_back(i);//
    }

    sort(res.begin(),res.end());

    cout << res.size() <<"\n";
    for(auto val : res){
        cout << val <<" ";
    }
 
    return 0;
}