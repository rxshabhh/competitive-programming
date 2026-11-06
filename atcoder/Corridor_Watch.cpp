#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,d; cin>>m>>d;
    string s; cin>>s;

    string ans = s;

    for(int i=0;i<m;i++){
        if(s[i]=='G'){
            int start = max(0,i-d);
            int end = min(m-1,i+d);

            for(int j=start;j<=end;j++) ans[j]='G';
        }

    }

    int cnt =0;

    for(auto val : ans){
        if(val=='.') cnt++;
    }

    cout << cnt << "\n";

    return 0;
}