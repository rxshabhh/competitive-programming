#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int a,b,c; cin>>a>>b>>c;

        if(abs(a-b)==1 && abs(b-c)==1) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}