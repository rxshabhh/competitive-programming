#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;

    while(t--){

        int n; cin>>n;

        vector<ll> a(n); for(auto &x : a) cin>>x;

        vector<ll> pre_odd(n,0), pre_even(n,0);

        map<ll,int> mpp;

        pre_even[0] = a[0];

        mpp[pre_odd[0]-pre_even[0]]++;

        bool ok = false;

        for(int i=1;i<n;i++){

            pre_odd[i] = pre_odd[i-1];
            pre_even[i] = pre_even[i-1];

            if(i%2) pre_odd[i] += a[i];
            else pre_even[i] += a[i];

            mpp[pre_odd[i]-pre_even[i]]++;

            if(mpp[pre_odd[i]-pre_even[i]]==2 || pre_odd[i]-pre_even[i]==0 ){
                ok = true;
                break;


            }
        }

        if(ok) cout <<"YES\n";
        else cout << "NO\n";

        // vector<int> pre(n);
        // pre[0] = a[0];

        // for(int i=1;i<n;i++){
        //     pre[i] = pre[i-1]+ a[i];
        // }

        // bool ok = false;

        // for(int i=1;i<n;i++){
        //     if(a[i-1] == a[i]){
        //         ok = true;
        //         break;
        //     }
        // }

        // if(ok) cout << "YES\n";
        // else cout << "NO\n";
    }

    return 0;
}