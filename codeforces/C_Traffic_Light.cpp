#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        char c; cin>>c;
        string s;cin>>s;

        if(c=='g'){
            cout << 0<<"\n";
            continue;
        }

        string st = s+s;

        int m=st.size();

        vector<int> next(m);

        int last = -1;
        for(int i=m-1;i>=0;i--){
            if(st[i]=='g'){
                last = i;
            
            }
            next[i] = last;
        }

        int cnt =0;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                cnt = max(cnt,next[i]-i);
            }
        }



        

        cout << cnt << "\n";










    }

    return 0;
}