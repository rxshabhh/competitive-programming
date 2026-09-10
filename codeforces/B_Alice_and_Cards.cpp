#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool func(int x, int k, vector<int>& a){

    vector<int> st;

    int cnt=0;

    for(int val : a){

        while(!st.empty() && val-st.back()>=x){
            st.pop_back();
            cnt++;

        }

        st.push_back(val);
    }

    return cnt>=k;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){

        int n,k; cin>>n>>k;

        vector<int> a(n); for(auto &x : a) cin>>x;

        int l=1, h=1e9;

        int ans=-1;
        while(l<=h){

            int mid = l+(h-l)/2;

            if(func(mid,k,a)){
                ans = mid;
                l =mid+1;
            }
            else h=mid-1;
        }

        cout << ans << "\n";
    }

    return 0;
}