#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        int k; cin>>k;
        vector<int> a(k); for(auto &x : a) cin>>x;

        int cnt =0;
        int cnt2=0;
        for(int val : a){
            if(val>=3) cnt++;
            if(val%2==0) cnt2++;
        }



        if(k==1 && a[0]>3){
            cout << "YES\n";
        }

        else if(cnt>0){
            cout << "YES\n";
        }
        else if(cnt2 >=2){
            cout << "YES\n";
        }
        else cout << "NO\n";



        
    }

    return 0;
}