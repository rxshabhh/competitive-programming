#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        vector<ll> a(n); for(auto &x : a) cin>>x;

        // ll mxidx = INT_MIN;

        // vector<ll> res;

        // while(res.size()!=n){

        //     mxidx = max_element(a.begin(),a.end())-a.begin();  <-- tle bcause of this

        //     a[mxidx] -= k;
        //     if(a[mxidx]<=0){
        //         res.push_back(mxidx+1);
        //     }

            
        // }

        // for(auto val : res){
        //     cout << val << " ";
        // }
        // cout << "\n";

        vector<pair<ll,ll>> res;

        for(int i=0;i<n;i++){
            int rem = a[i]%k;
            if(rem==0){
                rem = k;
            }

            res.push_back({-rem,i+1});
        }

        sort(res.begin(),res.end());

        for(auto val : res){
            cout << val.second << " ";
        }
        cout << "\n";
        
    }
    

    return 0;
}