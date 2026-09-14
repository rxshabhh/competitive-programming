#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    int t; cin>>t;

    while(t--){

        int n,m; cin>>n>>m;

        vector<int> a(n); for(auto &x : a) cin>>x;

        priority_queue<int> pq;

        ll sum=0;

        for(int i=0;i<m-1;i++){
            pq.push(a[i]);
            sum += a[i];

        }

        ll mx = LLONG_MIN;

        for(int i=m-1;i<n;i++){

            ll cnt = 1LL * m*(a[i]) - sum;
            if(cnt > mx){
                mx = cnt;
            }

            if(m>1){

                if(a[i] < pq.top()){
                    sum = sum - pq.top()+ a[i];
                    pq.pop();
                    pq.push(a[i]);

                }
            }
        }

        cout << mx << "\n";
    }

    return 0;
}