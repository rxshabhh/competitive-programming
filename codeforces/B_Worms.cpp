#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    // vector<int> a(n); for(auto &x : a) cin>>x;

    vector<int> pre(n);
    for(int i=0;i<n;i++){
        int x; cin>>x;
        pre[i] = (i==0? x : pre[i-1]+x);
    }

    int m; cin>>m;

    while(m--){

        int q; cin>>q;

        auto it = lower_bound(pre.begin(),pre.end(),q);
        cout << (it -pre.begin())+1 << "\n";

    }

    // vector<int> q(m); for(auto &x : q) cin>>x;

    // vector<int> ans;

    // for(int search : q){
    //     int left =1;

    //     for(int i=0;i<n;i++){
            
    //         int right = left + a[i]-1;

    //         if(search>=left && search<=right){
    //             ans.push_back(i+1);
    //             break;
    //         }

    //         left =right+1;

    //     }

        

    // }

    // for(auto val : ans){
    //     cout << val << '\n';
    // }
    

    return 0;
}