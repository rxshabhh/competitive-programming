#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        string s; cin>>s;

        vector<int> inv;

        int c0=0;
        for(int i=n-1;i>=0;i--){

            if(a[i]==0){
                c0++;
            }

            else inv.push_back(c0);
        }

        reverse(inv.begin(),inv.end());

        int m = inv.size();

        vector<ll> pre(m+1,0);

        for(int i=0;i<m;i++){
            pre[i+1] = pre[i] + inv[i];
        }

        ll curr=0,cnt=0,right=m;

        while(right>0 && inv[right-1]<=cnt) right--;

        ll ans=0;
        if(curr<right){
            ans = (pre[right]-pre[curr]) - (right-curr)*cnt;
        }

        cout << ans << " ";

        for(int i=0;i<n;i++){
            if(s[i]=='0') cnt++;
            else curr++;
            while(right>0 && inv[right-1]<=cnt) right--;
            ans =0;
            if(curr<right){
                ans = (pre[right]-pre[curr]) - (right-curr)*cnt;

            }

            cout << ans << " ";
        }

        cout << endl;


    }

    return 0;
}