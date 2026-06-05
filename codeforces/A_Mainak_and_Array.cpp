#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        if(n==1) cout << 0 << "\n";

        else{

        

            int ans = INT_MIN;

            ans = max(ans,a[n-1] - (*min_element(a.begin(),a.end()-1))); 

            ans = max(ans,(*max_element(a.begin()+1,a.end())) - a[0]);  

        
            for(int i=1;i<n;i++){
                ans = max(ans, a[i-1]-a[i]);


            }
            ans = max(ans,a[n-1]-a[0]);
    

            cout << ans << "\n";

        }



    }

    return 0;
}