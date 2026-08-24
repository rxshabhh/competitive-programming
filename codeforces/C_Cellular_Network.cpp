#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m; cin>>n>>m;
    
    vector<ll> cities(n); for(auto &x : cities) cin>>x;
    vector<ll> towers(m); for(auto &x : towers) cin>>x;

    ll r = LLONG_MIN;

    for(int i=0;i<n;i++){

        ll tower_right = lower_bound(towers.begin(),towers.end(),cities[i]) - towers.begin();

        ll tower_leff = tower_right - 1;

        ll min_r = LLONG_MAX;

        if(tower_right < m){

            min_r = min(min_r, towers[tower_right]-cities[i]);

        }

        if(tower_leff>=0){

            min_r = min(min_r, cities[i]-towers[tower_leff]);
            
        }

        r = max(r,min_r);

    }

    cout << r;

    return 0;
}