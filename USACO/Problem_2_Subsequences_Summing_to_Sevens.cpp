#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<int> a(n); for(auto &x : a) cin>>x;

    vector<int> first_occ(7,-2);

    ll pre=0;
    int mx=0;

    first_occ[0]=-1;

    for(int i=0;i<n;i++){

        pre += a[i];
        int rem = pre%7;

        if(first_occ[rem]==-2){
            first_occ[rem] =i;
        }
        else{
            mx = max(mx, i-first_occ[rem]);
        }
    }

    cout << mx;

    return 0;
}