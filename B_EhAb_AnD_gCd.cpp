#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {

    
    

        ll x; cin>>x;

        // for(ll g=1;g*g<=x;g++){

        //     if(x%g !=0) continue; 

        //     ll div[2] = {g,x/g};

        //     for(auto d : div){

        //         ll p = x/d -1;

        //         if(p<1) continue;

        //         for(ll m=1;m*m<=p;m++){

        //             if(p%m) continue;

        //             ll n = p/m;

        //             if(__gcd(n,m)==1){

        //                 ll a = d*m;
        //                 ll b = d*n;

        //                 cout << a << " " << b << "\n";
        //                 return;
        //             }
        //         }
        //     }

            
        // }

        // cout << -1 << "\n";

        cout << 1 << " " << x-1 << "\n";
    

    
}

int main(){
        
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}