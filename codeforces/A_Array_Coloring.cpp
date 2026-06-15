#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n); for(auto &x :a ) cin>>x;

        int cnt = 0;
        for(auto val : a){
            if(val%2==1) cnt++;
        }

        if(cnt%2==1) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}