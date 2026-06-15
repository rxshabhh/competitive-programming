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

        map<int,int> mpp;

        for(int i=0;i<n;i++){
            mpp[a[i]]++;
        }

        int s = mpp.size();

        if(s>=3) cout << "No\n";
        else if(s==1) cout << "Yes\n";
        else{

            int c1 = mpp.begin()->second;
            int c2 = mpp.rbegin()->second;

            if(n%2==0 && c1==c2) cout << "Yes\n";

            else if(n%2==1 && abs(c1-c2)==1) cout << "Yes\n";
            else cout << "No\n";
        }
    }

    return 0;
}