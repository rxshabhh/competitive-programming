#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        int ans=0;

        if(n%2){
            ans = ((n-1)/2) + ((n-1)/2)*((n-1)/2);
        }
        else{
            ans = (n/2)*(n/2);
        }

        cout << ans << "\n";
    }

    return 0;
}