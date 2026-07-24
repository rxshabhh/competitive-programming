#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k,s; cin>>n>>k>>s;

    // implementation error
    // vector<ll> ans;

    // ll step = (s+k-1)/k;
    // if(step>n) cout << "NO\n";
    // else{
    //     int K=k;
    //     while(K--){
    //         ans.push_back(step+1);
    //         ans.push_back(1);
    //         K-=2;

    //     }

    //     for(auto val : ans){
    //         cout << val << " ";
    //     }


    // }



    if(s<k || s> k*(n-1)){
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";

    ll curr = 1;

    while(k>0){

        ll d = min(n-1,s-k+1); // main part
        /*
        s is your total distance 

        k - 1 is the number of jumps you still have to make after this one

        Because every jump must be at least a distance of 1, you have to keep k - 1 distance in reserve.
        */

        if(curr+d<=n) curr+=d;
        else curr-=d;
        

        cout << curr << " ";
        s-=d;
        k--;
    }
    cout << "\n";
    return 0;




}