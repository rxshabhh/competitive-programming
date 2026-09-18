#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// brute force

void solve(){

    int n; cin>>n;
    vector<int> a(n),b(n);

    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    vector<int> ans(n);

    int j=0;
    ans[0] = min(a[0],b[0]);
    a[0] -= min(a[0],b[0]);

    while(j<n){

        for(int i=1;i<n;i++){
            ans[i+j] = min(a[i-1+j],b[i+j]);
            a[i+j-1] -= min(a[i+j-1],b[i+j]);
        }
        j++;
    }

    for(auto val : ans){
        cout << val << " ";
    }
    cout<<"\n";
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