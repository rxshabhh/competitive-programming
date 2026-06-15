#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        bool okay = false;

        for(int j=1;j<n-1;j++){

            int i=-1;
            int k=-1;

            for(int left = 0;left<j;left++){
                if(a[left]<a[j]){
                    i = left;
                    break;
                }
            }

            for(int right = j+1;right<n;right++){
                if(a[right]<a[j]){
                    k = right;
                    break;
                }
            }

            if(i!=-1 && k!=-1){
                cout << "YES\n";
                cout << i+1 << " " << j+1 << " " << k+1 <<"\n";
                okay = true;
                break;
            }
        }

        if(okay==false) cout << "NO\n";
    }

    return 0;
}