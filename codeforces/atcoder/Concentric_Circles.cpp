#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t; cin>>t;
    while(t--){

        ll px,py,qx,qy,rx,ry,sx,sy; cin>>px>>py>>qx>>qy>>rx>>ry>>sx>>sy;

        ll pqx = qx-px;
        ll pqy= qy-py;
        ll rsx=sx-rx;

        ll rsy = sy-ry;

        ll cp = (pqx*rsy) - (pqy*rsx);
        if(cp!=0){
            cout <<"Yes\n";
        }

        else{

            ll midx = (rx+sx-px-qx);
            ll midy = (ry+sy-py-qy);

            ll dp = (midx * pqx)+ (midy*pqy);

            if(dp==0) cout << "Yes\n";
            else cout << "No\n";
        }


    }
    return 0;
}