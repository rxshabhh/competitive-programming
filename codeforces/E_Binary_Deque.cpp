#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){

    int n,k; cin>>n>>k;

    vector<int> a(n); for(auto &x : a) cin>>x;

    unordered_map<int,int> freq;

    int pre=0;
    int mx=0;

    for(int i=0;i<n;i++){
        pre += a[i];

        if(pre==k){
            mx = i+1;
        }

        if(freq.find(pre-k) != freq.end()){
            int curr = i-freq[pre-k];
            mx = max(mx, curr);
        }

        if(freq.find(pre) == freq.end()){
            freq[pre] = i;
        }
    }

    if(mx<=0) cout << -1 << "\n";
    else cout << n-mx << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}