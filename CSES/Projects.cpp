#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct project{
    int s,e,p; // start, end, price
};

vector<project> a;
vector<ll> dp;
vector<int> starts; // store start of each project --> BS

ll func(int idx){

    if(idx==a.size()) return 0;

    if(dp[idx]!=-1) return dp[idx];

    ll ans = func(idx+1);

    // nxt to prevent overlap
    ll nxt = upper_bound(starts.begin(),starts.end(),a[idx].e)-starts.begin();

    ans = max(ans, (ll)a[idx].p + func(nxt));

    return dp[idx] = ans;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n;cin>>n;
    
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >>a[i].s >> a[i].e >> a[i].p;
    }

    sort(a.begin(),a.end(),[](project &x, project &y){
        return x.s < y.s;
    });

    starts.resize(n);

    for(int i=0;i<n;++i){
        starts[i] = a[i].s;
    }

    dp.assign(n,-1);
    
    cout << func(0);
    return 0;
}