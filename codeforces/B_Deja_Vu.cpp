#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){

    int n,q; cin>>n>>q;
    vector<int> a(n); for(auto &x : a) cin>>x;
    vector<int> x(q); for(auto &y : x) cin>>y;

    vector<int> valid;

    for(int i=0;i<q;i++){
        
        if(valid.empty() || x[i] < valid.back()){
            valid.push_back(x[i]);
        }
    }

    for(int i=0;i<valid.size();i++){

        int div = (1<< valid[i]);

        for(int j=0;j<n;j++){
            if(a[j]%div ==0){
                a[j] += (1<< (valid[i]-1));
            }
        }
    }

    for(auto val : a){
        cout << val << " ";
    }
    cout << "\n";
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}