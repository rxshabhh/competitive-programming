#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        vector<int> b(n); for(auto &x : b) cin>>x;

        int suma =0, sumb=0;

        for(int val : a){
            suma^=val;
        }

        for(int val : b){
            sumb^=val;
        }

        a.push_back(0);
        b.push_back(0);

        int x = suma^sumb;

        for(int i=0;i<=n;i++){

            a[i] ^= x;
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a==b){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }

    return 0;
}