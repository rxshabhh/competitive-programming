#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll mn = INT_MAX,mx=INT_MIN;
        for (int i=0;i<n;i++){
            ll x;cin>>x;
            mx = max(mx,x);
            mn=min(mn,x);
        }
        cout<<mx-mn+1<<'\n';
   

    }

    return 0;
}