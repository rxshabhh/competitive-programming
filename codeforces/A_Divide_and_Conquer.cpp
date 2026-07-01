#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int x,y; cin>>x>>y;\

        bool ok = false;

        for(int i=0;i<=x;i++){
            if(x==(y*i)){
                ok = true;
                break;
                
            }
        }
        if(ok) cout <<"YES\n";
        else cout <<"NO\n";
    }

    return 0;
}