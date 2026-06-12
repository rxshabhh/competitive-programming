#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;
    while(t--){

        ll x,n; cin>>x>>n;
        
        ll pos;
        
        if(n%4==0 ) pos = 0;
        else if(n%4==1) pos = -n;
        else if(n%4==2) pos = 1;
        else if(n%4==3){
            pos = (n+1);
        }

        if(x&1) pos = x - pos;
        else pos = x+pos;

        cout << pos << "\n";

    }

    return 0;
}