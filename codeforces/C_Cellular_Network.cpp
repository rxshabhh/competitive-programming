#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int mid, vector<int>& a, vector<int>& b){
    
    int n = a.size();

    

    for(int i=0;i<n;i++){
        bool ok = false;

        auto it = lower_bound(b.begin(),b.end(),a[i]);

        if(it!=b.end()){
            if(abs(*it-a[i]) <= mid){
                ok = true;
            
            }
        }

        if(it!=b.begin()){

            it--;
            if(abs(*it-a[i]) <= mid){
                ok = true;
            }
        }

        if(!ok) return false;
    }

    return true;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;

    vector<int> a(n); for(auto &x : a) cin>>x;

    vector<int> b(m); for(auto &x : b) cin>>x;

    int l = 0;

    int r = 2e9;

    int ans = INT_MAX;

    sort(b.begin(),b.end());

    while(l<=r){

        int mid = l + (r-l)/2;

        if(check(mid,a,b)){
            ans = min(ans,mid);
            r=mid-1;
        }
        else l =mid+1;
    }

    cout << ans;

    return 0;
}