#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
    if i is fix, then we need to find j --> Binary Search cause complete search --> time complexity
*/

void solve(){

    int n; cin>>n;
    
    vector<int> a(n+1);

    for(int i=1;i<=n;i++) cin>>a[i];

    ll ans =0;
    vector<int> valid;

    for(int j=1;j<=n;j++){

        if(j>a[j]){

            int cnt = lower_bound(valid.begin(),valid.end(),a[j]) - valid.begin();
            ans += cnt;
            valid.push_back(j);
        }
    }

    cout << ans << "\n";
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