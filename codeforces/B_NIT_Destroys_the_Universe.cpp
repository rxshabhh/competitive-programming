#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<ll> a(n); for(auto &x : a) cin>>x;

        ll c0 = 0;

        for(auto val : a){

            if(val==0) c0++;
        }

        bool foundzero = false;

        ll left = 0;
        ll right = n-1;

        while(a[left]==0) left++;
        while(a[right]==0) right--;

        for(int i=left;i<=right;i++){
            if(a[i]==0){
                foundzero = true;
            }
        }

        if(c0==n) cout << 0 << "\n";
        else if(!foundzero) cout << 1 << "\n";
        else cout << 2 << "\n";

    }

    return 0;
}