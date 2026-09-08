#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        ll x,y,k; cin>>x>>y>>k;

        ll cnt =0;

        ll i=0;
        while(i<k && x+i<=y){
            cnt += (y+i)%(x+i);
            i++;
        }

        if(i<k){
            ll rem =k-i;
            cnt += rem*(y-x);
        }

        cout << cnt << "\n";
    }

    return 0;
}