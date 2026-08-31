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

        int check = a[0];

        vector<int> ans;

        ans.push_back(0);

        

        for(int i=1;i<n;i++){
            int cnt =0;

            int xorr = check ^ a[i];

            if(xorr == (check | a[i])) cnt++;
            if(xorr < min(check,a[i])) cnt++;

            if(cnt){
                ans.push_back(cnt);
            }
            else ans.push_back(-1);

            cnt = 0;
        }

        for(auto val : ans){
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}