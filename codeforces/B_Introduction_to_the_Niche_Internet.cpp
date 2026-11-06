#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n,k; cin>>n>>k;

    vector<ll> a(n); for(auto &x : a) cin>>x;

    sort(a.begin(),a.end());

    if(a[0]==a[n-1]){

        if(k==n){
            cout << "YES\n";
            for(auto val : a) cout << val << " ";
            cout << "\n";
        }

        else{
            cout << "NO\n";
        }
        return;
    }

    vector<ll> ans;

    for(int i=n-k;i<n;i++) ans.push_back(a[i]);
    for(int i=n-k-1;i>=0;i--) ans.push_back(a[i]);

    int cnt =0; ll sum=0;

    for(int i=0;i<n;i++){

        if((ll)ans[i]*i >= sum){
            cnt++;
        }
        sum += ans[i];
    }

    if(cnt==k){
        cout << "YES\n";
        for(auto val : ans){
            cout << val << " ";

        }
        cout << "\n";
    }
    else cout << "NO\n";


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