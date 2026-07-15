#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        ll a,b; cin>>a>>b;

        // ll ops=0;

        // ll g = __gcd(a,b);
        // a /=g;
        // b/=g;

        // if(a!=1 && b!=1){
        //     cout << -1 << '\n';
        //     continue;
        // }

        // a = max(a,b);

        // while(a>1){

            
        //     if(a%8==0){
        //         a = a>>3;
        //         ops++;
        //     }
        //     else if(a%4==0){
        //         a= a>>2;
        //         ops++;
        //     } 
        //     else if(a%2==0){
        //         a = a>>1;
        //         ops++;
        //     }
        //     else{
        //         ops =-1;
        //         break;
        //     }
        // }

        // cout << ops << "\n";

        ll ra=a,rb=b;

        while(ra%2==0) ra/=2;
        while(rb%2==0) rb/=2;


        if(ra!=rb){
            cout << -1 << '\n';
            
        }
        else{

            a/=ra;  // Normalise a to the odd factor
            b/=rb;

            a =log2(a);
            b=log2(b);

            ll ans = ceil(abs(a-b)/3.0);
            cout << ans << "\n";




        }

    }

    return 0;
}