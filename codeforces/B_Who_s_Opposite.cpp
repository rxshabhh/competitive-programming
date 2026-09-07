#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int a,b,c; cin>>a>>b>>c;

        int total = abs(a-b)*2;



        if(a>total || b>total || c>total){
            cout << -1 << "\n";
        }
        else{
            int ans = c + abs(a-b);
            if(ans>total) ans -= total;
            cout << ans << "\n";
            
        }


    }

    

    return 0;
}