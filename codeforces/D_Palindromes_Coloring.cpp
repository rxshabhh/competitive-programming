#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){

        int n,k; cin>>n>>k;
        string s; cin>>s;
        map<char,int> mpp;

        set<char> st;

        string ans= "";

        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
            st.insert(s[i]);
        }

        if(st.size()==1){
            cout << (n/k) << "\n";
        }

        else if(st.size()==n){
            cout << 1 << "\n";
        }


        else{
            int c =0;

            vector<string> temp;

            for(auto &val : mpp){

                if(val.second==1) c++;

                if(val.second%2==0){
                    temp.push_back(val.first * val.second);
                }
            }

            sort(temp.begin(),temp.end());

            ans = temp[0].size();



            if(c>0) cout << ans+1 << "\n";
            else cout << ans << "\n";


        }
        

        
    }

    return 0;
}