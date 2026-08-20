#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int func(int dist, int mx){

    int speed=0, t=0;

    for(int curr=1;;curr++){
        
        speed+=curr; // s += d as t is per second
        t++;
        if(speed>=dist) return t;

        if(curr>=mx){
            speed+=curr;
            t++;
            if(speed>=dist) return t;
        }
    }


}



int main() {

    freopen("race.in","r",stdin);
    freopen("race.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int k,n; cin>>k>>n;

    vector<int> x(n); for(auto &it : x) cin>>it;

    for(int i=0;i<n;i++){
        cout << func(k,x[i]) << "\n";
    }

    return 0;
}