#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// this approch i was trying will give me TLE or MLE 

// vector<ll> make(vector<ll>& a){

//     int n = a.size();
//     int sz = (n*(n+1))/2;

//     vector<ll> b(sz);

//     // make b ?? 
// }
// int solve(int l, int r, vector<ll>& v){ // let v = pre


//     return pre[r]-pre[l]+1;


// }
ll func(ll idx, vector<ll>& pre, vector<ll>& prepreA, vector<ll>& len){

    if(idx==0) return 0;

    ll k = upper_bound(len.begin(),len.end(),idx) - len.begin() -1;

    ll rem = idx - len[k];

    return prepreA[k] + pre[rem];
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n,q; cin>>n>>q;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];

    //vector<ll> b = make(a);

    // vector<ll> pre(b.size()+1,0);

    // pre[0] = b[0];
    // for(int i=1;i<b.size();i++){
    //     pre[i] = pre[i-1] + b[i];
    // }

    vector<ll> preA(n+1,0), prepreA(n+1,0);
    for(int i=1;i<=n;i++) preA[i] = preA[i-1] + a[i];
    for(int i=1;i<=n;i++) prepreA[i] = prepreA[i-1]+preA[i];


    vector<ll> len(n+1,0);

    for(int i=1;i<=n;i++){
        len[i] = 1LL* i*(i+1)/2;
    }


    while(q--){

        ll l,r; cin>>l>>r;
        cout << func(r,preA,prepreA,len) - func(l-1,preA,prepreA,len) << "\n";

        
    }

    return 0;
}