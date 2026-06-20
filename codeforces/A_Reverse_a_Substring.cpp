#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin>>n;
    string s; cin>>s;

    int ok =0;
    for(int i=0;i<n-1;i++){
        if(s[i]>s[i+1]){
            cout << "YES\n";
            cout<< i+1 << " " << i+2<<"\n";
            ok=1;
            break;
        }
    }

    if(ok==0) cout<<"NO\n";

    return 0;
}