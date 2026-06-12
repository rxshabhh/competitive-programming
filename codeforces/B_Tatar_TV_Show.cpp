#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;

    while(t--) {
        int n,k;cin>>n>>k;

        string s;cin>>s;
        bool ok=true;

        for(int i=0;i<k;i++) {
            int cnt=0;
            for(int j = i;j<n;j+=k)
                cnt+=(s[j]=='1');
            if(cnt&1){
                ok=false;
                break;
            }
        }

        cout <<(ok?"YES":"NO")<<"\n";
    }

    return 0;
}