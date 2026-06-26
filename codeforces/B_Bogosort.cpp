#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int n;cin >>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        sort(a.begin(),a.end(),greater<int>());

        for(int val : a){
            cout << val << " ";
        }

        cout << "\n";
    }

    return 0;
}