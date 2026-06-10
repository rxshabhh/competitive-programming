#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        ll n;cin>>n;

        vector<ll> a(n); for(auto &x : a) cin>>x;

         ll cnt = 0;

        for(int i=n-2;i>=0;i--){
            
            while(a[i]>=a[i+1] && a[i]>0){
                a[i] = (a[i]>>1);
                cnt++;
            }

            if(a[i]>=a[i+1]){
                cnt = -1;
                break;
            }
        }

        cout << cnt <<"\n";
    }

    return 0;
}