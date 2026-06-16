#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        string s; cin>>s;

        int n=s.size();

        int c0 =0, c1=0;

        int len = 0;

        for(int val : s){
            if(val=='0') c0++;
            else c1++;
        }

        for(int i=0;i<n;i++){

            if(s[i]=='0' && c1>0){
                c1--;
                len++;
            }

            else if(s[i]=='1' && c0>0){
                c0--;
                len++;
            }

            else break;
        }

        cout << n-len << "\n";

        
    }
    

    return 0;
}