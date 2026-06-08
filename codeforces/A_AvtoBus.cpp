#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;

        if(n%2!=0 || n<4) cout << -1 << "\n";

        else{
            cout << (n+5)/6 << " " << (n+3)/4 << "\n";
        }
    }

    return 0;
}