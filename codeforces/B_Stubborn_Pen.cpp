#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){

    int n; cin>>n;
    string s; cin>>s;

    int cnt=0;

    char curr = 'R';
    for(int i=0;i<n;i++){

        if(s[i]!=curr) cnt++;

        s[i] = (s[i]=='R' ? curr='B' : curr='R');
    }

    // string st;
    // for(int i=0;i<n;i++){
    //     if(i%2==0) st.push_back('R');
    //     else st.push_back('B');
    // }

    // for(int i=0;i<n;i++){

    //     if(s[i] != st[i]) cnt++;
    // }

    // for(int i=1;i<n;i++){

    //     if(s[0]=='B'){
    //         cnt++;
    //         s[0] = 'R';
    //     }

    //     if(s[i-1]==s[i]){
    //         cnt++;
    //         (s[i-1]=='B' ? (s[i]='R') : (s[i]='B');
    //     }
    // }

  

    cout << cnt << "\n";
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