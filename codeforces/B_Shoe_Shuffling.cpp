#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> s(n); for(auto &x : s) cin>>x;

        map<int,int> freq;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }

        bool unique = false;

        for(auto val : freq){
            if(val.second==1){
                unique = true;
                break;
            }
        }

        if(unique){
            cout << -1 << "\n";
            continue;
        }

        vector<int> idx(n);
        for(int i=0;i<n;i++) idx[i] = i+1;

        int l=0,r=0;

        while(r<n){

            if(s[l]==s[r]){
                r++;
            }

            else{

                rotate(idx.begin()+l,idx.begin()+l+1,idx.begin()+r);
                l=r;
            }
        }

        rotate(idx.begin()+l, idx.begin()+l+1, idx.begin()+r);


        for(int val : idx){
            cout << val << " ";
        }
        cout << "\n";

    }

    return 0;
}