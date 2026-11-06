#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; cin>>n>>k;

    vector<int> a(n); for(auto &x : a) cin>>x;

    int curr = accumulate(a.begin(),a.begin()+k,0);

    int best=curr;
    int ans =0;

    for(int i=1;i+k<=n;i++){
        curr += a[i+k-1] - a[i-1];

        if(curr < best){best = curr; ans=i;}
        
    }

    cout << ans+1;

    return 0;
}