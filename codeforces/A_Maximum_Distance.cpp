#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<int> x(n), y(n);
    for(auto &it : x) cin >> it;
    for(auto &it2 : y) cin>>it2;

    int mx =0;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int dx = x[i]-x[j];
            int dy = y[i]-y[j];

            int sq =  dx*dx + dy*dy;
            mx = max(mx,sq);
        }
    }

    cout << mx << "\n";
    return 0;
}