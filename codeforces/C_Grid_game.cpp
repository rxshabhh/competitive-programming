#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;

    // wrong as overlap problem can occur and for index>4 nothing is defined

    // vector<pair<int,int>> ans;

    // for(int i=0;i<s.size();i++){
    //     int k;
    //     if(i<4) k =i+1;
    //     else if(i==4) k=1;
    //     else k = (i%4);
    //     if(s[i]=='0'){
        
    //         ans.push_back({1,k++});
    //     }
    //     else{
    //         ans.push_back({3,k++});
    //     }
    // }

    // for(auto val : ans){
    //     cout << val.first << " " << val.second <<"\n";
    // }


    bool vertical = false;
    int horizontal = 0;

    for(auto ch : s){
        if(ch=='0'){
            if(!vertical) cout << "1 1\n";
            else cout << "3 1\n";
            vertical = !vertical;
        }
        else{
            cout << horizontal+1 << " 3\n";
            horizontal = (horizontal+1)%4;
        }
    }
    

    return 0;
}