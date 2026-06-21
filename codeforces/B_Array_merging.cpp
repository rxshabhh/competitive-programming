#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> a(n); for(auto &x: a) cin>>x;

        vector<ll> b(n); for(auto &x : b) cin>>x;

        vector<ll> suba(2*n+1,0);
        vector<ll> subb(2*n+1,0);

        ll cnt=1;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]) cnt++;
            else{
                suba[a[i-1]] =max(suba[a[i-1]],cnt); // stores max. consecutive soo far
                cnt=1;
            }
        }
        suba[a[n-1]] =max(suba[a[n-1]],cnt);

        cnt = 1;

        for(int i=1;i<n;i++){
            if(b[i]==b[i-1]) cnt++;
            else{
                subb[b[i-1]] =max(subb[b[i-1]],cnt); // stores max. consecutive soo far
                cnt=1;
            }
        }
        subb[b[n-1]] =max(subb[b[n-1]],cnt);

        ll mx=-1;
        for(int i=1;i<=2*n;i++){
            mx=max(mx,suba[i]+subb[i]);
        }

        cout << mx << "\n";





        
    }

    return 0;
}