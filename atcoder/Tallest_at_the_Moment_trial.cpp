#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// faces TLE 9*10^10 even with long long cause of whole approach O(N*Q)

// Binary Search + Prefix_Suffix Fix



ll func(ll x, vector<pair<ll,ll>>& v){
    ll need = (x+0.5)+1;
    ll mx = INT_MIN;
    for(auto &val : v){

        if(val.second >= need){
            mx = max(mx,val.first);
        }

        
    }

    return mx;





}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin>>n;

    vector<pair<ll,ll>> v;
    while(n--){

        ll h,l; cin>>h>>l;

        v.push_back({h,l});

    }

    ll q; cin>>q;

    vector<ll> t(q); for(auto &x : t) cin>>x;
    vector<ll> answ;

    for(int i=0;i<t.size();i++){
        ll ans = func(t[i],v);
        answ.push_back(ans);
        
    
    }

    for(auto val : answ){
      cout << val << "\n";

    }


    

    return 0;
}