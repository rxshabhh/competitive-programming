#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;

        vector<char> a(n);
        for(auto &x : a) cin>>x;

        int white =0;

        for(int i=0;i<k;i++){
            if(a[i]=='W') white++;
        }

        int ans = white;

        for(int i=k;i<n;i++){
            if(a[i-k]=='W') white--;
            if(a[i]=='W') white++;
            

            ans =min(ans,white);
        }

        cout << ans << "\n";
    }

    return 0;
}