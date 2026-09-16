#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9+7;

vector<vector<ll>> adj;
vector<ll> par;

vector<ll> len;
vector<ll> ranks;

ll find(ll x){
    
    if(par[x]!=x){
        par[x] = find(par[x]);
    }

    return par[x];

}
ll modpow(ll a, ll b){

    ll res = 1;
    a %= mod;

    while(b>0){
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b >>=1;



    }

    return res;

}

void merge(ll a, ll b){

    ll l =find(a);
    ll r =find(b);

    if(l!=r){

        if(ranks[l]>ranks[r]){
            par[r] = l;
            len[l] += len[r];
        }
        else if(ranks[l]<ranks[r]){
            par[l] = r;
            len[r]+= len[l];
        }
        else{
            par[l]=r;
            ranks[r]++;
            len[r] += len[l];
        }
    
    }

    



}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k; cin>>n>>k;

    par.resize(n+1);
    ranks.resize(n+1,0);
    len.resize(n+1,1);

    for(int i=1;i<=n;i++){
        par[i] =i;
    }

    for(int i=0;i<n-1;i++){

        ll x,y,z; cin>>x>>y>>z;

        if(z==0){
            merge(x,y);
        }

        
    }

    ll total = modpow(n,k);

    ll bad =0;

    for(ll i=1;i<=n;i++){
        if(find(i)==i){
            bad = (bad + modpow(len[i],k)) % mod;
        }
    }

    cout << (total - bad + mod) % mod << "\n";

    



    return 0;
}