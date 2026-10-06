#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// pair<int,int> func(int l, int r, vector<int>& a){

//     pair<int,int> p;

//     int a1 = max_element(a.begin(),a.end()) - a.begin();    // pure array ka haii yeh
//     int a2 = min_element(a.begin(),a.end()) - a.begin();

//     if(a1!=a2) p.push_back({a1,a2});
//     else p.push_back({-1,-1});

//     return p;
// }


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        
        int n; cin>>n;
        vector<int> a(n); for(auto &x : a) cin>>x;

        vector<int> idx(n,-1);

        for(int i=1;i<n;i++){

            if(a[i]!=a[i-1]){
                idx[i] = i-1;
            }
            else{
                idx[i] = idx[i-1];
            }
        }

   //     vector<int> pre(n+1,0);

        // for(int i=1;i<n;i++){
        //     pre[i] = pre[i-1] + a[i];
        // }

        int q; cin>>q;

        // vector<pair<int,int>> v;

        while(q--){

            int l,r; cin>>l>>r;

            // v.push_back(func(l,r,a));

            int a1=-1,a2=-1;

            // int res = 0;

            // for(int i=l+1;i<=r;i++){

            //     if(idx[i]!=idx[i-1]){
            //         a1 = idx[i];
            //         a2 = idx[i-1];
            //         break;
            //     }
    
            // }

            l--; r--;
            if(idx[r]>=l){
                
                cout << idx[r]+1 << " " << r+1 << "\n";
            }
            else{
                cout << "-1 -1\n";
            }



            // while(l<r){
            //     if(pre[r]-pre[l] >0){
            //         a1 = l;
            //         a2 = r;
            //     }
            //     l++;
            //     r--;
            // }

            //cout << a1 << " " << a2 << "\n";

            

        }

        // for(int i=0;i<v.size();i++){
        //     cout << v[i].first << " " << v[i].second << "\n";
        // }

    }

    

    return 0;
}