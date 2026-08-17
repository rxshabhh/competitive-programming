#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    freopen("lifeguards.in", "r",stdin);
    freopen("lifeguards.out","w",stdout);


    int n; cin>>n;

    int N=n;
    int mx=0;

    vector<int> starts, ends;
    while(N--){
        int x,y; cin>>x>>y;

        starts.push_back(x);
        ends.push_back(y);
    }

    for(int i=0;i<n;i++){
        vector<bool> ans(1005,false);
        int cnt=0;

        for(int j=0;j<n;j++){

            if(j==i) continue;

            for(int t=starts[j];t<=ends[j]-1;t++){
                ans[t] = true;
            }
        }

        for(auto val : ans){
            if(val) cnt++;
        }
        mx=max(mx,cnt);
        cnt=0;
    }




    cout << mx << "\n";



    return 0;
}