#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        int n; cin>>n;

        vector<int> a(n); for(auto &x : a) cin>>x;

        vector<int> temp;

        for(int i=0;i<n;i++){
            if((i+1)!=a[i]) {
                temp.push_back(a[i]);
            }
        }

        bool ok = true;

        for(int i=1;i<temp.size();i++){

            if(temp[i] >= temp[i-1]){
                ok = false;
                break;
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";

        

        
    } 

    return 0;
}