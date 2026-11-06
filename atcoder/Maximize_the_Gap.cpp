#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(int x,vector<pair<int,int>> &v,int k){
    int cnt=0;
    ll last =-1; // for calc the earliest position of the last chosen interval

    for(auto &cl : v){
        int l =cl.first;
        int r=cl.second;

        if(l>=last){
            cnt++;
            last = 1LL*r+x;
            if(cnt>=k) return true;
        }
    }
    // last is like we want x range so if an interval is choosen then we'll choose the interval
    // r+x where r is last index of the range.

    return false;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; cin>>n>>k;

    vector<pair<int,int>> v;

    int N =n;
    while(N--){
        int l,r; cin>>l>>r;
        v.push_back({l,r});
    }

    // my approach will create 2 loops i.e brute force and I m confused what to do after choosing
    // non-overlapping k clothes cause then i have to calc. distances with each other

    sort(v.begin(),v.end(),[](auto &a, auto &b){ // for greedy optimization
        return a.second < b.second;
    });

    int lo =0;
    int hi = 1e9;

    while(lo<hi){
        int mid = lo+(hi-lo+1)/2;
        if(check(mid,v,k)) lo =mid;
        else hi=mid-1;
    }

    if(lo==0) cout << -1;
    else cout << lo;

    return 0;
}