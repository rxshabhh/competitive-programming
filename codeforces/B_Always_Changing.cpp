#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int n; cin>>n;

        string s; cin>>s;

        int c0=0,c1=0;

        // for(int i=0;i<n;i++){
        //     if(s[i]=='0') c0++;
        //     else c1++;
        // }

        // if((c0==0 && c1!=0) || (c1==0 && c0!=0)){
        //     cout << -1 << "\n";
        //     continue;
        // }

        // int st =-1;
        // int cnt=0;

        // for(int i=1;i<n;i++){
        //     if(s[i-1]==s[i] && st!=s[i]){
        //         st = s[i];
        //         s.erase(i,i);
        //         cnt++;
        //     }
        // }

        // cout << cnt << "\n";

        int i=0;
        while(i<n){

            // counting the blocks of 0s and 1s 
            int j=i;
            while(j<n && s[j]==s[i]) j++;
            if(s[i]=='0') cnt0 += (j-i-1);  // suppose the block size is 3 of 0s, then add 2 to it as we need 
            // to delete 2 of them to make it alternating
            else cnt1 += (j-i-1);
            i=j;
        }


    }

    return 0;
}