#include <bits/stdc++.h>
using namespace std;

// unsolved

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        string s; cin>>s;

        int ops=0;

        if(n==2) cout << 0<<"\n";

        map<char,int> mpp;

        for(int i=0;i<n;i++){
            mpp[s[i]-'a']++;
        }

        for(auto &val : mpp){
            if(val.second % 2 ==1){
                ops++;
                val.second--;

                
            }
        }

        int cnt =0;
        for(auto &val : mpp){
            cnt += val.second;
        }

        if(cnt%2==1) ops++;
        
        

        cout << ops<<'\n';
    }

    return 0;
}