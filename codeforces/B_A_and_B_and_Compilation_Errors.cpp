#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;
    vector<int> b(n-1); for(auto &x : b) cin>>x;
    vector<int> c(n-2); for(auto &x : c) cin>>x;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    
    vector<int> ans;

    set_difference(a.begin(),a.end(),b.begin(),b.end(),back_inserter(ans));
    set_difference(b.begin(),b.end(),c.begin(),c.end(),back_inserter(ans));

    for(auto val : ans){
        cout << val << "\n";
    }
    

    return 0;
}