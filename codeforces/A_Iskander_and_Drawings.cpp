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

        int len =0;
        int mx =0;

        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                len++;
                mx = max(mx,len);
            }
            else{
                len=0;
            }
        }



        cout << (mx+1)/2 << "\n";
    }

    return 0;
}