#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;

    vector<ll> pre(n+1,0);


    sort(a.begin(),a.end());

    int cnt=0;

    for(int i=0;i<n;i++){
        

        if(a[i]>=pre[cnt]){

            cnt++;
            pre[cnt] = pre[cnt-1] + a[i];

        }

    }

    cout << cnt;



    return 0;
}