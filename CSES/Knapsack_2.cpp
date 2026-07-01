#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[105][100005];

ll func(ll idx,ll x, vector<ll> &w, vector<ll> &v ){ // min weight required for x value

    ll n= w.size();

    if(x==0) return 0;
    if(idx<0) return 1e15;
    if(dp[idx][x]!=-1) return dp[idx][x];


    ll ans = func(idx-1,x,w,v);
    if(x-v[idx]>=0) ans = min(ans, func(idx-1,x-v[idx],w,v)+w[idx]);

    return dp[idx][x] =ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(dp,-1,sizeof(dp));

    ll n,x; cin>>n>>x;
    vector<ll> w(n),v(n);
    
    for(ll i=0;i<n;i++){
        cin >> w[i] >> v[i];
    }

    int mx = 1e5;
    for(int i=mx;i>=0;--i){
        if(func(n-1,i,w,v)<=x){
            cout << i <<"\n";
            break;
        }
    }


    



    return 0;
}