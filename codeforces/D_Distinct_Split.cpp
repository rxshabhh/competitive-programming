#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        string s; cin>>s;

        // set<char> a,b;

        // for(int i=0;i<n;i++){
        //     if(a.count(s[i])==0){
        //         a.insert(s[i]);
        //     }
        //     else{
                
        //         for(int j=i;j<n;j++){
        //             b.insert(s[j]);
        //         }
        //         break;
        //     }
        // }

        // cout << a.size()+b.size() <<"\n";

        // no proof for my solution
        // counter-example: aabab --> my code:3 but answer is 4

        set<char> st;

        vector<ll> pre(n+1,0);
        vector<ll> suff(n+1,0);

        for(ll i=1;i<n;i++){
            st.insert(s[i-1]);
            pre[i] = st.size();
        }

        st.clear();

        for(ll i=n;i>=1;i--){
            st.insert(s[i-1]);
            suff[i] = st.size();
        }

        ll ans =0;

        for(ll i=0;i<n;i++){
            ans =max(ans,pre[i]+suff[i+1]);
        }

        cout << ans <<"\n";
    }

    return 0;
}