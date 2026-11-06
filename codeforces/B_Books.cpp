#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,t; cin>>n>>t;

    vector<int> a(n); for(auto &x : a) cin>>x;

    int sum=0;
    int i=0,ans=0;

    for(int j=0;j<n;j++){

        sum += a[j];

        while(sum>t) sum -=a[i++];
        ans = max(ans,j-i+1);
    }

    cout << ans;

    return 0;
}