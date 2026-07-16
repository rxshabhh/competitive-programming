#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;

    while(t--){
        ll n,c; cin>>n>>c;
        vector<ll> a(n); for(auto &x : a) cin>>x;

        sort(a.begin(),a.end());

        // if(c==0){
        //     cout << accumulate(a.begin(),a.end(),0) << "\n";

        // }

        // else if(n%2==0){
        //     ll l=0,r=n-1;
        //     ll sum =0;

        //     while(l<r){

        //         sum += (max(a[l],a[r]) - c);
        //         l++;
        //         r--;
        //     }

        //     cout << sum << "\n";
        // }
        // else{

        //     ll sum=0;

        //     ll l=0,r=n-1;
        //     ll mid = (n/2);

        //     while(l!=mid && r!=mid){
        //         sum += (max(a[l],a[r])-c);
        //         l++;
        //         r--;
        //     }
        //     sum += (a[mid]-c);

        //     cout << sum << "\n";
        // }

        ll sum=0;
        for(auto val : a){
            sum += (val-c);
        }


        for(ll i=0;i<(n/2);i++){
            if(a[i]<c){
                sum += (c-a[i]);
            }
        }

        cout << sum << "\n";
    }

    return 0;
}