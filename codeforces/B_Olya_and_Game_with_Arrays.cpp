#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;

    

    while(t--){

        vector<vector<int>> v;
 
        int n;cin>>n;

        int N = n;
        while(n--){
            int m; cin>>m;
            vector<int> a(m); for(auto &x : a) cin>>x;

            sort(a.begin(),a.end());

            v.push_back(a);
        }

        ll sum =0;
        int mnfirst = INT_MAX;
        int mnsecond = INT_MAX;

        for(auto &x : v){
            sum+=x[1];
            mnfirst = min(mnfirst,x[0]);
            mnsecond =min(mnsecond,x[1]);

        }

        cout << sum - mnsecond+ mnfirst <<"\n";




    }

    return 0;
}