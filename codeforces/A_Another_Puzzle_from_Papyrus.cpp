#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t;cin>>t;
    while(t--){

        int n,c; cin>>n>>c;

        vector<int> a(n); for(auto &x : a) cin>>x;
        vector<int> b(n); for(auto &x : b) cin>>x;

        
        int cnt =0;


        for(int i=0;i<n;i++){
            if(a[i]>b[i]) cnt += (a[i]-b[i]);
            else if(a[i]<b[i]){
                cnt = -1;
                break;
            }

        }

        sort(b.begin(),b.end());
        int cnt1 =c;
        sort(a.begin(),a.end());

        for(int i=0;i<n;i++){

            if(a[i]<b[i]){
                cnt1=-1;
                break;
            }
            cnt1 += a[i]-b[i];
        }


        int ans = 0;
        if(cnt==-1 && cnt1==-1) ans=-1;
        else if(cnt==-1) ans=cnt1;
        else if(cnt1==-1) ans=cnt;
        else ans = min(cnt,cnt1);
        cout << ans << "\n";

        
    }

    return 0;
}