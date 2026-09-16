#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll check(ll idx, vector<ll>& a, ll c){

    ll sum =0;

    for(int i=1;i<a.size();i++){

        sum += (a[i]+2*idx) * (a[i]+2*idx);

        if(sum>c) return -1;

        
    }

    return sum;

}

void solve(){
    ll n,c; cin>>n>>c;

    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    ll w=0;

    ll low = 1, high=1e9;

    while(low<=high){

        ll mid = low+(high-low)/2;

        ll r = check(mid,a,c);

        if(r == c){
            w = mid;
            break;
        }
        else if(r ==-1){
            high = mid-1;
        }
        else low = mid+1;
    }

    cout << w << "\n";
    // vector<ll> pre(n+1,0), pres(n+1,0);

    // for(int i=1;i<n;i++){
    //     pre[i+1] = pre[i] + a[i];
    //     pres[i+1] = pres[i] + (a[i] * a[i]);
    // }

    // ll w=0;

    // for(int i=1;i<=n;i++){

    //     if(pres[i]>=c && (pres[i]-c)%4 ==0){
    //         w = (c-pres[i])/4;
    //         break;
    //     }
    //     else if((pres[i]+pre[i]) <= c && (c - (pres[i]+pre[i]))% n ==0){
    //         w = (c - (pres[i]+pre[i])) / n;
    //         break;
    //     }

    // }

    // cout << w << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}