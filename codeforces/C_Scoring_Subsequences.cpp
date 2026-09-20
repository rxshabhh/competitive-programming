#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// int fact(int n){

//     if(n==1 || n==0) return 1;
//     else return n*fact(n-1);
// }

// int score(int n, vector<int>& a){

//     int prod =1;
//     for(int i=0;i<n;i++){
//         prod *= a[i];
//     }

//     int p = fact(n);

//     return (prod / p);

// }


// why not 1st try: I m stuck, for a particulat score I have to calculate how many sub-sequences are there with same score, how to count
// those and that too in linear time??? any pattern I can't notice here??
void solve(){

    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;

    
    priority_queue<int,vector<int>, greater<int>> pq;

    for(int k=0;k<n;k++){

        pq.push(a[k]);

        while(pq.top() < pq.size()) pq.pop();

        cout << pq.size() << " ";
    }
    cout << "\n";



    // for(int i=n-1;i>=0;i--){

    //     int res = score(i+1,a);

    //     ans.push_back(res);
    // }

    // for(auto val : ans){
    //     cout << val << " ";
    // }


    // cout << "\n";

    
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        solve();
    }

    return 0;
}