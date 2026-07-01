#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int x){

    string st = to_string(x);
    set<char> s;
    for(int i=0;i<st.size();i++){
        s.insert(st[i]);
    }

    if(s.size()<=2) return true;
    return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        ll x; cin>>x;

        ll ans=1;

        for(ll i=0;i<to_string(x).size();i++){
            ans *= 10;
        }

        cout << ans+1 <<"\n";


    }

    return 0;
}