#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t; cin>>t;
    while(t--){

        ll n,x; cin>>n>>x;

        vector<ll> a(n); for(auto &x : a) cin>>x;

        ll low = 1, high = *max_element(a.begin(),a.end())+x;
        ll cnt =0;
        while(low<=high){

            ll mid = low+(high-low)/2;
            ll w=0;
            for(int i=0;i<n;i++){
                if(mid > a[i]) w += mid-a[i];
                if(w>x) break;
            }
            if(w<=x){
                cnt = max(cnt,mid);
                low=mid+1;
            }
            else if(w>x){
                high = mid-1;
            }

        }

        cout << cnt << "\n";
    }

    return 0;
}