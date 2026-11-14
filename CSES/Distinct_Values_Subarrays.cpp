#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<int> v(n); for(auto &x : v) cin>>x;

    int left =0; ll cnt=0;

    map<int,int> mpp;

    for(int right=0;right<n;right++){

        mpp[v[right]]++;

        while(mpp[v[right]]>1){
            mpp[v[left]]--;
            left++;
        }

        cnt += right-left+1;
    }

    cout << cnt;

    

    return 0;
}