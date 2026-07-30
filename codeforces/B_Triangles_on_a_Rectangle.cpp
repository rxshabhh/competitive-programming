#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    int t; cin>>t;
    while(t--){

        ll w,h; cin>>w>>h;

        ll area = INT_MIN;

        for(int i=0;i<4;i++){

            ll k; cin>>k;
            ll first, last;

            for(int j=0;j<k;j++){
                
                ll x; cin>>x;
                if(j==0) first = x;
                if(j==k-1) last = x;
            }

            ll base = last-first;
            ll he;
            if(i<=1) he= h;
            else he= w;


            area = max(area, base*he);
        }

        cout << area << "\n";
    }

    return 0;
}