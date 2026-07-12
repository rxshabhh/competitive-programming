#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;

    

    while(t--){
        int n;cin>>n;

        if(n==1){
            cout << 1 << "\n";
            continue;
        }

        if(n==2){
            cout << -1 << "\n";
            continue;
        }

        vector<ll> a = {2,4,6};

        ll sum = 12;

        for(int i=3;i<n;i++){
            a.push_back(sum);
            sum *= 2;

        }

        for(auto val : a){
            cout << val << ' ';
        }
        cout << "\n";



    }

    return 0;
}