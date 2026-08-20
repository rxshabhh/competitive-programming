#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {


    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    string s; cin>>s;
    int cnt=0;


    // this approach is wrong as well as taking too much time complexity
    // int l=0,r=0;
    // for(int i=0;i<n;i++){
    //     if(s[i]=='G' && (i+1)%2){
    //         l=i; r=i;

    //         while(r<n && (s[i]=='G' && i%2)) r++;

    //         if((r-l+1)%2) r++;
    //     }

    //     reverse(s.begin()+l,s.begin()+r);
    //     cnt++;

    // }

    // cout << cnt << "\n";

    // we need to count the pairs in the strings HH,GG,HG,GH


    for(int i=n-2;i>=0;i-=2){
        string sub = s.substr(i,2);
        if(sub[0]==sub[1]) {continue;}
        
        if((sub=="HG" && cnt%2) || (sub=="GH" && cnt%2==0)) cnt++;
    }

    cout << cnt << "\n";



    return 0;
}