#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,d; cin>>n>>d;

    vector<ll> a(n); for(auto &x : a) cin>>x;

    vector<int> vis(n,0);

    sort(a.begin(),a.end());
    int cnt =0;
    
    

    int i=0,j=n-1;

    while(i<=j){
        int k= d/a[j] +1;
        if(k>(j-i+1)) break;
        cnt++;
        i += k-1;
        j--;
    }

    cout << cnt;



    return 0;
}