#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        int n,m; cin>>n>>m;
        vector<int> a(n); for(auto &x : a) cin>>x;

        vector<int> freq(m+1,0);
        for(int i=0;i<n;i++){
            freq[a[i]]++;
        }

        int mx=0;
        int curr =0;
        for(int i=m;i>=1;i--){

            curr += freq[i];

            int cnt=curr;

            if(2*i<=m){
                cnt += freq[2*i];
            }

            mx = max(mx,cnt);
        }

        cout << mx << "\n";
    }

    return 0;
}