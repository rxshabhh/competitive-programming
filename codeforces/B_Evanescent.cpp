#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;
        string s; cin>>s;

        int k=0;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]) k++;
        }

        int ans =0;

        for(int i=1;i<n-1;i++){

            int org = (s[i]!=s[i-1]) + (s[i+1]!=s[i]);
            int nw = (s[i-1]!=s[i+1]);
            int diff = nw-org;

            ans = min(ans,diff);
        }

        cout << k+ans+1 << "\n";


    }

    return 0;
}