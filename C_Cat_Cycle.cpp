#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        int n,k; cin>>n>>k;

        if(n%2==0){

            if(k>n) cout << (k-1)%n+1 << "\n";
            else cout << k << "\n";
        }
        else{
            int c = n/2;
            // if(coincide == k){
            //     cout << (k+1) <<"\n";
            // }

            // else if(coincide < k){
            //     if(k+2<=n) cout << (k+2) << "\n";
            //     else cout << (k+2)%n << "\n";
            // }
            // else{
            //     if(k<=n) cout << k << "\n";
            //     else cout << k%n << "\n";
            // }

            int extra = (k-1)/ c;

            if(k+extra >n) cout << (k+extra-1)%n+1 << "\n";
            else cout << (k+extra) << "\n";
        }
    }

    return 0;
}