#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        ll a; cin>>a;

        // int x = __builtin_popcountll(n); // no. of set bits

        // bool even;

        // if(x%2){
        //     even = false;
        // }
        // else even = true;

        // if(!even){
        //     cout << gcd(a,1)<<"\n";
        // }
        // else{
        //     
        // }

        int k=0;

        while((1<<k)<=a){
            k++;
        }

        int mx = (1<<k)-1;

        int ans =1;
        if(mx!=a){
            cout << mx << '\n';

            /*
                suppose we asked to calculate b in this case;

                b = mx -a; just opposite of a set bits
            
            */
        }
        else{

            for(int i=2;i*i<=a;i++){
                if(a%i==0){
                    ans = a/i;
                    break;
                }
            }

            cout << ans << "\n";
        }

        






    }

    return 0;
}