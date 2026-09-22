#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        int sum=a[0], ans=a[0];

        for(int i=1;i<n;i++){

            if(abs(a[i]%2) != abs(a[i-1]%2)){
                sum = max(a[i] , sum+a[i]);

            }

            else sum=a[i];

            ans = max(ans,sum);
        }

        cout << ans << "\n";
    }

    return 0;
}