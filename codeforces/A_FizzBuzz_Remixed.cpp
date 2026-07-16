#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        ll n; cin>>n;



        ll cnt =0;

        if(n%15==0){
            cnt = (n/15)*3 +1;
        }
        else if(n%15==1){
            cnt = (n/15)*3 +2;

        }
        else{
            cnt = (n/15)*3 +3;
        }

        cout << cnt << "\n";


    }

    return 0;
}