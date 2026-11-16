#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;

    int mx = *max_element(a.begin(),a.end());
    int mn= *min_element(a.begin(),a.end());

    if(mx!=9){
        cout << -1;
    }
    else{

        cout << mn;
    }

    return 0;
}