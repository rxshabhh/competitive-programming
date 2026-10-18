#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        ll n; cin>>n;

        if(n%2==0){
            cout << (n/2)-1 << " " << (n/2) << " " << 1 << "\n";
        }
        else{

            int m = (n-1)/2;
            if(m%2==0){
                cout << m-1 << " " << m+1 << " " << 1  << "\n";
            }
            else cout << m-2 << " " << m+2 << " " << 1 << "\n";
        }
    }

    return 0;
}