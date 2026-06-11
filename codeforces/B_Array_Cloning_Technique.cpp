#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        map<int,int> mp;

        for(int i=0;i<n;i++){ // store freq with element
            mp[a[i]]++;
        }

        int cf = 0;
        for(auto val : mp){
            cf = max(cf,val.second);
        }

        int ops = 0;

        while(cf<n){
            ops++;
            if(cf*2 <= n){
                ops += cf;
                cf *= 2;
            }
            else{
                ops += (n-cf);
                cf=n;
            }
        }

        cout << ops << "\n";



    }

    return 0;
}