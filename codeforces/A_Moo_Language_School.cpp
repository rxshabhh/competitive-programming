#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;

        string s; cin>>s;
            int cnt=0;

        for(int i=0;i<n;i+=k){
            bool ok = true;

            for(int j=0;j<k;j++){
                if(s[i+j]=='0'){
                    ok = false;
                    break;
                }
            }

            if(ok) cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}