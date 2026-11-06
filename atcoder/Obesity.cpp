#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll h,w; cin>>h>>w;

    if(10000*w >= 25*h*h) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}