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

        int sum = accumulate(a.begin(),a.end(),0);

        vector<int> freq(1005,0);

        int mx=0, mxf=0;

        for(int i=0;i<n;i++){
            freq[a[i]]++;

            if(freq[a[i]]>mxf){
                mxf=freq[a[i]];

                mx = a[i];
            }



        }

        int cnt = n-mxf;
        int l = cnt+2;

        if(mxf>l){
            int r = mxf -l;
            sum -= r*mx;
        }

    



        cout << sum << "\n";
    }

    return 0;
}