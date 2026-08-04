#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        // vector<int> b(n); for(auto &x : b) cin>>x;

        // sort(b.begin(),b.end());

        // vector<int> a(n);

        // for(int i=0;i<n;i++){

        //     int sum = accumulate(b.begin()+1,b.begin()+i+1,0);
        //     a[i] = sum - b[1];
        // }

        // for(int val : a){
        //     if(val < 0){
        //         cout << -1 << "\n";
        //         break;
        //     }
        //     else{
        //         cout << val << " ";

        //     }

        multiset<ll> b;
        for(int i=0;i<n;i++){
            ll x; cin>>x;
            b.insert(x);
        }

        ll sum=0;

        vector<ll> a(n);

        bool ok = true;

        for(int i=0;i<n;i++){

            auto it = b.lower_bound(1ll-sum);

            if(it == b.end()){
                ok = false;
                break;
            }

            sum += *it;
            a[i] = sum;
            b.erase(it);
        }

        if(ok){

            for(auto val : a){
                cout << val << " ";
            }
            cout << "\n";
        }
        else cout << -1 << "\n";

        
    }

    return 0;
}