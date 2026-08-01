#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        int n,m; cin>>n>>m;

        vector<int> a(n), b(m);
        for(auto &x : a) cin>>x;
        for(auto &x : b) cin>>x;

        bool ok = true;

        if(n<2*m){
            cout << "NO\n";
            continue;
        }
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        for(int i=0;i<m;i++){
            if(a[i]>b[i] || a[n-m+i]<b[i]){
                ok = false;
                break;
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
        
    }

    return 0;
}