#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// brute force

void solve(){

    int n; cin>>n;

    vector<int> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<int> b(n+1);
    for(int i=1;i<=n;i++) cin>>b[i];

    vector<ll> pre(n+1,0);

    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1] + b[i];
    }

    vector<ll> diff(n+2,0), extra(n+2,0);

    for(int i=1;i<=n;i++){
        int k= upper_bound(pre.begin()+i,pre.begin()+n+1,a[i]+pre[i-1]) - pre.begin() - 1;
        diff[i]++; diff[k+1]--;

        if(k<n) extra[k+1] += a[i]-pre[k] + pre[i-1];
    }


    vector<ll> ans;

    ll c=0;
    for(int i=1;i<=n;i++){
        c += diff[i];
        ans.push_back(c*b[i] + extra[i]);
    }

    for(auto val : ans){
        cout << val << " ";
    }
    cout << "\n";
    // vector<int> a(n),b(n);

    // for(auto &x : a) cin>>x;
    // for(auto &x : b) cin>>x;

    // vector<int> ans(n);

    // int j=0;
    // ans[0] = min(a[0],b[0]);
    // a[0] -= min(a[0],b[0]);

    // while(j<n){

    //     for(int i=1;i<n;i++){
    //         ans[i+j] = min(a[i-1+j],b[i+j]);
    //         a[i+j-1] -= min(a[i+j-1],b[i+j]);
    //     }
    //     j++;
    // }

    // for(auto val : ans){
    //     cout << val << " ";
    // }
    // cout<<"\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}