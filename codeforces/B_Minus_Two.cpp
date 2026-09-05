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

        int c1=0,c2=0,c3=0;

        for(int i=0;i<n;i++){

            if(a[i]%2){
                c1++;
            }
            else if(a[i]%4==0){
                c2++;
            }
            else c3++;
        }

        cout << max(c1,max(c2,c3)) << "\n";

    }
    return 0;
}