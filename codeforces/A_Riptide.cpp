#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int a,b,c; cin>>a>>b>>c;

        vector<int> v = {a,b,c};
        sort(v.begin(),v.end());

        cout << min((v[2]-v[1]),(v[1]-v[0])) << "\n";
    }

    return 0;
}