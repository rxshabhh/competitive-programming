#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; cin>>n>>k;

    vector<pair<int,int>> mpp(n);

    for(int i=0;i<n;i++){
        cin >> mpp[i].second >> mpp[i].first;
    }

    ll cnt =0, ans =0;

    sort(mpp.rbegin(),mpp.rend());

    priority_queue<int,vector<int>,greater<int>> pq;

    for(auto& val : mpp){

        pq.push(val.second);
        cnt += val.second;
        if((int)pq.size()>k){
            cnt -= pq.top();
            pq.pop();

        }

        ans = max(ans, cnt*val.first);
    }

    cout << ans;

    // vector<int> t(n), b(n);

    // for(auto &x : t) cin>>x;
    // for(auto &x : b) cin>>b;

    // unordered_map<int,int> mpp;

    // for(int i=0;i<n;i++){
    //     mpp[b[i]] = t[i];
    // }

    // sort(mpp.begin(),mpp.end());

    // int ans = INT_MIN;

    // int bmin = mpp[0].first;

    // int cnt =0;



    // while(cnt<=k){

    //     int sum =0;
    //     sum += bmin* mpp[cnt].second;

    //     ans = max(ans,sum);

    //     cnt++;

    
    // }

    // cout << ans;

    return 0;
}