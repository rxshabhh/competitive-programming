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

        for(int i=0;i<n;i++){
            if(s[i]=='0') c0++;
            else c1++;
        }

        if((c0==0 && c1!=0) || (c1==0 && c0!=0)){
            cout << -1 << "\n";
            continue;
        }

        int st =-1;
        int cnt=0;

        for(int i=1;i<n;i++){
            if(s[i-1]==s[i] && st!=s[i]){
                st = s[i];
                s.erase(i,i);
                cnt++;
            }
        }

        cout << cnt << "\n";


    }

    return 0;
}