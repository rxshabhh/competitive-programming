#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){

    int m,s; cin>>m>>s;

    if((s==0 && m>1) || (s>9*m)){
        cout << "-1 -1\n";
        return;
    }

    if(s==0 && m==1){
        cout << "0 0\n";
        return;
    }

    string mx="";

    int sum_mx = s;

    for(int i=0;i<m;i++){
        int d = min(9,sum_mx);
        mx += to_string(d);
        sum_mx -= d;
    }

    string mn = "";

    int sum_mn = s-1;

    for(int i=0;i<m-1;i++){

        int d = min(9,sum_mn);
        mn += to_string(d);
        sum_mn -= d;
    }

    mn += to_string(sum_mn + 1);

    reverse(mn.begin(),mn.end());

    cout << mn << " " << mx;



    // Implementation wrong but idea correct

    // if((m!=0 && s==0) || (m==0 && s!=0)){
    //     cout << -1 << " " << -1 << "\n";
    //     return;
    // }

    // string ans1 = "";

    // int left = s;

    // while(left>9){
    //     left = left-9;
    //     if(left>0){
    //         ans1+= to_string(left);
    //     }
    //     ans1 += '9';
    // }

    // string ans2 = "";

    // for(int i=0;i<m-1;i++){
    //     ans2 += '9';
    // }

    // ans2 += to_string(s-(9*(m-1)));

    // cout << ans1 << " " << ans2;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}