#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        ll n; cin>>n;

        int x = __builtin_popcountll(n); // no. of set bits

        bool even;

        if(x%2){
            even = false;
        }
        else even = true;

        if(!even){
            cout << gcd(a,1)<<"\n";
        }
        else{
            //
        }
    }

    return 0;
}