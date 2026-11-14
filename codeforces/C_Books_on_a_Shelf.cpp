#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
    In this question, first find the element with max. freq, before it is ascending order, after it is descending order
    k = elements before mx freq element + after it
*/

void solve(){

    int n; cin>>n;
    vector<int> a(n); for(auto &x : a) cin>>x;

    map<int,int> mpp;

    for(int i=0;i<n;i++){
        mpp[a[i]]++;
    }

    vector<int> left,right,middle;


    for(auto& [num,cnt] : mpp){

        if(cnt>0){
            left.push_back(num);
            cnt--;
        }
        if(cnt>0){
            right.push_back(num);
            cnt--;
        }

        while(cnt>0){
            middle.push_back(num);
            cnt--;
        }
        
    }

   int k = left.size() + right.size();

   reverse(right.begin(),right.end());

   cout << k << "\n";

   for(auto val : left) cout << val << " ";
   for(auto val : middle) cout << val << " ";
   for(auto val : right) cout << val << " ";
   cout << "\n";





    

    // unordered_map<int,int> mpp;

    // for(int i=0;i<n;i++){
    //     mpp[a[i]]++;
    // }

    // int mx = *max_element(mpp.begin(),mpp.end());

    // vector<int> ans;
    // vector<int> temp = a;
    // sort(temp.begin(),temp.end());

    // for(int i=0;i<n;i++){

    //     if(temp[i] != mx) ans.push_back(temp[i]);

    // }
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