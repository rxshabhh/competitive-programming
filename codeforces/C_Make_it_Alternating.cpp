#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*

    intuituion is get the block of 0s or 1s, count the len and add len-1 to the ops count for min. ops

    the problem i m facing rn : i m not able to run a loop that can select a block in O(n^2), can do in O(n^3) but it's highly
    insufficient --> implementation problem
*/

const int mod = 998244353;

void solve(){

    string s; cin>>s;
    int n= s.size();

    ll ops = 0;

    ll seq =1;

    ll currlen = 1;
    for(int i=1;i<n;i++){

        if(s[i-1]==s[i]){
            currlen++;
        }
        else{
            ops += currlen-1;
            seq = (seq*currlen)%mod;
            currlen=1;
        }
    }

    if(currlen!=0){ ops += currlen-1; seq = (seq*currlen)%mod;}

    ll fact = 1;
    for(int i=1;i<=ops;i++){
        fact = (fact*i)%mod;
    }

    seq = (seq * fact * 1ll)%mod;



    

    

    

    // for(int i=1;i<n;i++){
    //     int j=-1;
    //     if(s[i-1]==s[i]){
    //         i = i-1;
    //         j=i;
    //         while(j<n && s[j-1]==s[j]) j++;
    //         int len = j-i+1;
    //         ops += len-1;
    //         seq += (len==0)?1 : len*2;
           
    //     }
    //     j=-1;
        
    // }

    cout << ops << " " << seq << "\n";


}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while(t--){
        solve();
    }

    

    return 0;
}