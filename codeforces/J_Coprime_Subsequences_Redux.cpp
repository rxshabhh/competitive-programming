#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mod = 1e9+7;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n,m; cin>>n>>m;

    vector<int> a(n); for(auto &x:a) cin>>x;

    vector<int> freq(m+1,0);
    for(int i=0;i<n;i++){
        freq[a[i]]++;
    }

    vector<ll> multiple_count(m+1,0);

    vector<ll> pow2(n+1,1);
    for(int i=1;i<=n;i++){
        pow2[i] = (pow2[i-1]*2)%mod;
    }


    // this will count the multiples of each number present in array
    // this loop will run in O(nlogn) cause of harmonic series
    for(int x=1;x<=m;x++){
        for(int k=x;k<=m;k+=x){
            multiple_count[x] += freq[k];
        }
    }

    vector<ll> ans(m+1,0);

    for(int x=m;x>=1;x--){
        ll curr = (pow2[multiple_count[x]]-1 + mod)%mod;

        // subtract the overcount

        for(int k=2*x;k<=m;k+=x){
            curr = (curr - ans[k]+mod)%mod;
        }

        ans[x] = curr;
    }

    for(int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }
    



    return 0;
}