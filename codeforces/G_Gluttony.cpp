#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;

    vector<pair<int,int>> v(n);

    for(int i=0;i<n;i++){
        v[i]={a[i],i};
    }

    sort(v.begin(),v.end());

    vector<int> ans(n);

    for(int i=0;i<n;i++){

        int org = v[i].second;

        int idx = (i+1)%n;

        ans[org] = v[idx].first;



    }

    


    for(int val : ans){
        cout << val << " ";
    }

    

    return 0;
}