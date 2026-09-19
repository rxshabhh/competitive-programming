#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dis_cost(ll p1, ll p2, map<ll,pair<ll,ll>>& mpp){



    // for(auto& [idx, it] : mpp){

    //     if(idx == p1){
    //         p1x = it.first;
    //         p1y = it.second;
    //     }
    //     else if(idx == p2){
    //         p2x = it.first;
    //         p2y = it.second;
    //     }
    // }

    ll p1x = mpp[p1].first, p1y = mpp[p1].second;
    ll p2x = mpp[p2].first, p2y = mpp[p2].second;

    ll res = llabs(p1x-p2x) + llabs(p1y-p2y);
    return res;
}

void solve(){

    ll n,k,a,b; cin>>n>>k>>a>>b;
    
    map<ll,pair<ll,ll>> mpp;

    for(int i=0;i<n;i++){

        ll x,y; cin>>x>>y;

        mpp[i+1] = {x,y};
    }

    ll cost =0;

    

    if(a<=k && b<=k){
        cost =0;
      
    }

    else{
        // a to (1,2,3...k) to b ---> for minimum cost, but how to implement it?

        // sort map based on based of points on 2d i guess

        ll da = LLONG_MAX, db = LLONG_MAX;

        for(ll i=1;i<=k;i++){

            da = min(da, dis_cost(a,i,mpp));
            db = min(db, dis_cost(b,i,mpp));


        }

        cost = dis_cost(a,b,mpp);
        if(k>0) cost = min(cost, da+db);

    }

    cout << cost << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}