#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;
    while(t--){
        string s; cin>>s;
        int cnt0 = 0, cnt1=0;

        for(auto val : s){
            if(val == '1'){
                cnt1++;
            }
            else cnt0++;
        }

        if(min(cnt0,cnt1)%2==0){
            cout << "NET\n";
        }
        else cout << "DA\n";
    }

    return 0;
}