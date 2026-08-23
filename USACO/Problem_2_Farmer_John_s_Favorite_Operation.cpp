#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(int n, ll m, vector<ll>& a){

    vector<ll> x(n);
    for(int i=0;i<n;i++){
        x[i] = (a[i]%m);
    }

    sort(x.begin(),x.end());

    vector<ll> b(3*n);
    
    for(int i = 0; i < n; i++) {
        b[i] = x[i] - m;         // Left block
        b[i + n] = x[i];         // Middle block
        b[i + 2 * n] = x[i] + m; // Right block
    }

    vector<ll> pre(3*n+1,0);

    for(int i=0;i<3*n;i++){
        pre[i+1]=pre[i]+b[i];
    }


    ll mn = LLONG_MAX;
    for(int i=n;i<2*n;i++){

        ll cost=0;
        ll target = b[i];

        ll left_count = (n%2==0) ? (n / 2 -1): (n/2);
        ll right_count = (n/2);

        ll leftsum = pre[i] - pre[i-left_count];
        cost += (target*left_count) - leftsum;


        ll right_sum = pre[i + right_count + 1] - pre[i + 1];
        cost += right_sum - (target * right_count);

        mn = min(mn, cost);
    }



    // int mn=INT_MAX, cnt=0;

    // for(int i=0;i<n;i++){
        
    //     int rem = a[i]-x;
    //     cnt += (rem % m);
    //     mn = min(mn,cnt);
    // }

    // mn = min(mn,cnt);

    // return mn;

    // vector<int> freq(m,-2);
    // freq[0]=-1;
    // int pre=0,cnt=0;
    // int idx =0;
    // int mn=0;

    // while(idx<n){
    //     for(int i=0;i<n;i++){
    //         pre += (a[i]-x[idx]);

    //         int rem = pre%m;

    //         if(freq[rem]==-2) freq[rem]=i;

    //         else{
    //             cnt += i-freq[rem];
    //         }
    //         mn = min(mn,cnt);
        

        
    //     }
    //     freq.clear();

    //     mn = min(mn,cnt);
    //     idx++;
    // }


    // return mn;

    return mn;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;

    while(t--){
        int n; ll m; cin>>n>>m;
        vector<ll> a(n); for(auto &x : a) cin>>x;

        cout << solve(n,m,a)<< "\n";
    }

    return 0;
}