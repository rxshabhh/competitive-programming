#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){

    int n; cin>>n;
    
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];

    vector<ll> pre(n+1,0);

    for(int i=1;i<=n;i++){
        pre[i] = pre[i-1]+a[i];
    }

    vector<ll> pre_mx(n+2,0), pre_mn(n+2,0);
    pre_mx[0] = pre_mn[0]=0;

    for(int i=1;i<=n;i++){

        pre_mx[i] = max(pre_mx[i-1],pre[i]);
        pre_mn[i] = min(pre_mn[i-1],pre[i]);


    }

    vector<ll> suff_mx(n+2,0), suff_mn(n+2,0);

    suff_mx[n] = suff_mn[n]=pre[n];

    for(int i=n-1;i>=0;i--){

        suff_mx[i] = max(suff_mx[i+1],pre[i]);
        suff_mn[i] = min(suff_mn[i+1],pre[i]);


    }

    ll ans = pre_mx[n] - pre_mn[n]+1;


    for(int k=1;k<=n;k++){

        ll x = -2LL * a[k];

        ll mx = max(pre_mx[k-1], suff_mx[k]+x);
        ll mn = min(pre_mn[k-1], suff_mn[k]+x);

        ans = max(ans, mx-mn+1);



    }

    cout << ans << "\n";



    // int pge=0,nge=0;
    // int sum =0;

    // int mx = max_element(a.begin(),a.end());
    // int mn = min_element(a.begin(),a.end());

    // for(auto val : a){
    //     if(val<0) nge++;
    //     else pge++;
    //     sum += (val);
    // }

    // if(nge==0 || pge==0){

    //     cout << abs(sum) +1;
    //     return;
    // }

    // if(nge>pge){

    //     sum += (-mx)*2;
        
    // }
    // else{
    //     sum += (mn*2);
        
    // }

    // cout << abs(sum)+1;


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();



    

    return 0;
}