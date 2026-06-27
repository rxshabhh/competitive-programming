#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;

    int ce=0,cw=0;
    for(auto val : s){
        if(val=='E') ce++;
        else cw++;
    }

    if(ce>cw) cout << "East";
    else cout << "West";

    return 0;
}