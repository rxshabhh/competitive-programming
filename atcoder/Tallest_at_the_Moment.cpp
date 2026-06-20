#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// int func(int x, vector<pair<int,int>>& v){
//     int need = x + 0.5;
//     int mx = INT_MIN;
//     for(auto &val : v){

//         if(val.second >= need){
//             mx = max(mx,val.first);
//         }

        
//     }

    

//     return mx;
    

// }

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    // while(n--){
    //     int h,l; cin>>h>>l;

    //     v.push_back({h,l});
    // }

    // int q; cin>>q;

    // vector<int> t(q); for(auto &x : t) cin>>x;
    // vector<int> answ;

    // for(int i=0;i<t.size();i++){
    //     int ans = func(t[i],v);
    //     answ.push_back(ans);
        
    
    // }

    // for(auto val : answ){
    //     cout << val << "\n";

    // }

    int n; cin>>n;
    vector<int> h(n),l(n);
    for(int i=0;i<n;i++){
        cin >>h[i]>>l[i];
    }

    vector<int> suffix(n);
    suffix[n-1] = h[n-1];

    for(int i=n-2;i>=0;i--){
        
        suffix[i] = max(suffix[i+1],h[i]);
    }

    int q; cin>>q;


    while(q--){
        int t;cin>>t;

        int idx = lower_bound(l.begin(),l.end(),t+1) - l.begin();

        cout << suffix[idx] << "\n";
    }
    

    return 0;
}