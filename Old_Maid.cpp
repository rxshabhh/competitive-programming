#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;

    unordered_map<int,int> mpp;

    for(int i=0;i<n;i++){
        mpp[a[i]]++;
    }

    int sum =0;

    for(auto &it : mpp){
        if(it.second%2){
            sum += it.first;
        }
    }

    cout << sum;

    return 0;
}