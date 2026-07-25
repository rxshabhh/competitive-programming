#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int n; cin>>n;

    vector<int> a(n); for(auto &x : a) cin>>x;

    int cnt =0;

    for(int i=1;i<n-1;i++){
        
        if(a[i-1]<a[i] && a[i]>a[i+1]) cnt++;

    }

    cout << cnt << "\n";

    return 0;
}