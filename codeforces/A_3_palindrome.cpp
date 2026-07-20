#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    if(n==3){
        cout << "aab";
    }
    else{
        string st = "aabb";

        for(int i=0;i<n;i++){
            cout << st[i%4];
        }
    }

    return 0;
}