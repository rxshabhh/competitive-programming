#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        ll n; cin>>n;
        n--;

        vector<ll> ans;
        ll p = log2(n);

        ll num =pow(2,p)-1;

        while(num>=0){
            ans.push_back(num);
            num--;
        }

        num = pow(2,p);
        while(num<=n){
            ans.push_back(num);
            num++;
        }

        for(auto val : ans){
            cout << val << " ";
        }
        cout << "\n";

    }

    return 0;
}