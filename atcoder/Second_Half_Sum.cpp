#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;

    int sum = accumulate(a.begin()+(n/2), a.end(),0);

    cout << sum;

    return 0;
}