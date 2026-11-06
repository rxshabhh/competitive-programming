#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll k,t; cin>>n>>k>>t;

    vector<ll> a(n); for(auto &x : a) cin>>x;


    ll curr_end=0;
    ll cnt =0;

    sort(a.begin(),a.end());

    for(int i=0;i<n;i++){

        ll target = min(a[i],t);
        if(target>curr_end){

            ll gap = target - curr_end;
            ll press = (gap+k-1)/k;

            cnt += press;
            curr_end += press*k;
        }

        curr_end = max(curr_end,a[i]+k);


    }

    
        if(curr_end < t){

            ll gap = t-curr_end;
            
            cnt += (gap+k-1)/k;

        }

    // int idx = a[0];
    // while(idx<t){
    //     for(int i=0;i<idx;i++){
    //         int diff = idx;

    //         if(diff==0){
    //         continue;
    //         }
    //         cnt += (diff/k)+1;

    //     }
    //     idx += k;
    // }

    // for(int i=0;i<n;i++){

    //     // if(min(t-a[i],a[i]) > k) cnt += min(t-a[i],a[i])/k;

    // }

    cout << cnt;


    
    return 0;
}

/*
    over-complicating things here, understood what can be done on paper, but fail to implement correctly
    and cross-check the output that will be produced
*/