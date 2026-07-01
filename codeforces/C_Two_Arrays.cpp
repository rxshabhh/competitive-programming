#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9+7;

// entirely a new concept


ll C(ll n, ll r){

    vector<vector<ll>> C(n+1, vector<ll>(n+1,0));

    for(int i=0;i<=n;i++){
        C[i][0] = C[i][i] = 1;

        for(int r=1;r<i;r++){
            C[i][r] = (C[i-1][r] + C[i-1][r-1])%mod;
        }
    }

    return C[n][r];

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m; cin>>n>>m;

    cout << (C(n+(2*m)-1,2*m))%mod << "\n";

    

    return 0;
}