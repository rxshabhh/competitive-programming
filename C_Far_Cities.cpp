#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


bool func(int u, int v, int d){
    cout << "?" << " " << u << " " << v << " " << d << endl;

    int ans; cin>>ans;
    
    if(ans==-1){
        cout.flush();
    }

    if(ans) return 1;
    else return 0;

    
}

void solve(){

    int n; cin>>n;
    int d=0,a=1;

    for(int v=2;v<=n;v++){
        while(d+1<n && func(1,v,d+1)==1){
            d++;
            a=v;

        }
    }

    int d2 =d,b=1;
    for(int v=1;v<=n;v++){
        if(v==a) continue;
        while(d2+1<n && func(a,v,d2+1)==1){
            d2++;
            b=v;
        }
    }

    cout << "!" << " " << a << " " << b << " " << d2 << endl;
}

int main() {

    int t;cin>>t;
    while(t--){
        solve();
    }

    return 0;
}