#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int n,x,y; cin>>n>>x>>y;

        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            cin >> a[i];
        }

        if(x+y > n){
            cout << "NO\n";
            continue;
        } 

        int g = __gcd(x,y);
        bool ok = true;

        for(int i=1;i<=n;i++){
            if(a[i]%g != i%g){
                ok = false;
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}