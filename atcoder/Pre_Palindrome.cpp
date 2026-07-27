#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;

    int n= s.size();
    int ans =0;

    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            int l = i, r=i+j;
            int cnt=0;
            while(l>=0 && r<n){
                if(s[l]!=s[r]) cnt++;
                if(cnt>1) break;

                ans++;
                l--;
                r++;

            }

        }
    }

    cout << ans << "\n";

    return 0;
}