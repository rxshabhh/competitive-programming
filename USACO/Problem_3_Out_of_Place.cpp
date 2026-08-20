#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    freopen("outofplace.in","r",stdin);
    freopen("outofplace.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    int N=n;
    vector<int> a(n);
    for(auto &x : a) cin>>x;

    int cnt=0;

    // lower bound always on sorted array as it uses binary search for the same

    vector<int> b = a;
    sort(b.begin(),b.end());

    for(int i=0;i<n;i++){
        if(a[i]!=b[i]) cnt++;
    }


    cout << cnt-1 << "\n";
    return 0;
}