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

        int i=0,j=n-1;
        int cnt =0;

        while(i<j){

            for(int k=i;k<=j;k++){
                if((a[k]>a[i] && a[k]<a[j]) || a[k]>a[j] && a[k]<a[i]) cnt++;
            }

            i++;
            j--;
        }
        

        cout << cnt << "\n";
    }

    return 0;
}