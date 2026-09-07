#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int a,b,c; cin>>a>>b>>c;

        int c1=0,c2=0,c3=0;

        c1 = max(0,max(b,c)-a+1);
        c2 = max(0,max(c,a)-b+1);
        c3 = max(0,max(a,b)-c+1);




        cout << c1 << " " << c2 << " " << c3 << "\n";
    }

    return 0;
}