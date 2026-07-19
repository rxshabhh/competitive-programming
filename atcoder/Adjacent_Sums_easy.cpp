#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int func(vector<int>& a, vector<int>& b, int parity,int ops){

    int n=a.size();
    for(int i=0;i<n-1;i++){

        parity = b[i]^parity;

        if(parity!=a[i+1]) ops++;

    }

    return ops;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;

    vector<int> a(n),b(n-1);

    for(auto &x : a) cin>>x;

    for(auto &x : b) cin>>x;

    int r1 = min(func(a,b,a[0],0),func(a,b,a[0]^1,1));

    cout << r1 << "\n";






    return 0;
}