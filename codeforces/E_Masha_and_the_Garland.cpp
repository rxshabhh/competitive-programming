#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n,q; cin>>n>>q;

        string s; cin>>s;
    
        vector<int> pre(n,0);
        for(int i=0;i<n-1;i++){
            pre[i+1] = pre[i] + (s[i]==s[i+1] ?1:0);
        }



        while(q--){
            int l,r,k; cin>>l>>r>>k;
            
            l--;r--;
            int c= pre[r]-pre[l];

            int ops = (c+1)/2;


            if(ops<=k) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}