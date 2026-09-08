#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        ll x,y; cin>>x>>y;

        ll mx = x+y;

        ll mn =0;

        for(int i=29;i>=0;i--){

            if((mx >> i) & 1){

                if(mn + (1 << i) <= x){
                    mn += (1 << i);
                }

            }
        }

        cout << mx << " " << (x-mn) << "\n";


        
        

        
    }

    return 0;
}