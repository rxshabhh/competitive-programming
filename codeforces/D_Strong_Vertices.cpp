#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n; cin>>n;
    vector<int> a(n),b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    vector<int> diff(n);

    for(int i=0;i<n;i++){
        diff[i] = a[i]-b[i];
    }

    int mx = *max_element(diff.begin(),diff.end());

    vector<int> ans;

    for(int i=0;i<n;i++){
        if(diff[i]==mx) ans.push_back(i+1);
    }

    sort(a.begin(),a.end());

    cout << ans.size() << "\n";
    for(auto val : ans){
        cout << val << " ";
    }
    cout << "\n";
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