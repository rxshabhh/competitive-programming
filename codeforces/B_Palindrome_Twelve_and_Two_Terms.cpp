#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        
        vector<int> p ={0,1,2,3,4,5,6,7,8,9,11,22};

        ll a = -1;
        for(int val : p){
            if(val<=n && (n-val)%12==0){
                a = val;
                break;
            }
        }

        if(a != -1){
            cout << a << " " << (n-a) << "\n";
        }
        else cout << -1 << "\n";
    }

    return 0;
}