#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;

    string target = "hello";

    int idx =0;
    
    for(auto c : s){
        if(c==target[idx]) idx++;

        if(idx==5) break;
    } 

    if(idx == 5) cout << "YES\n";
    else cout << "NO\n";

    // what's wrong was: what if we haven't found the letter itself, then it will give out of bound error as idx will be empty

    // vector<int> idx;

    // for(int i=0;i<s.size();i++){

    //     if(s[i]=='h'){
    //         idx.push_back(i);
    //         break;
    //     }
    // }

    // for(int i=0;i<s.size();i++){

    //     if(s[i]=='e' && idx[0]<i){
    //         idx.push_back(i);
    //         break;
    //     }
    // }

    // for(int i=0;i<s.size();i++){

    //     if(s[i]=='l' && idx[1]<i){
    //         idx.push_back(i);
    //         s[i] = '.';
    //         break;
    //     }
        
    // }

    // for(int i=0;i<s.size();i++){

    //     if(s[i]=='l' && idx[2]<i){
    //         idx.push_back(i);
    //         break;
    //     }
    // }

    // for(int i=0;i<s.size();i++){

    //     if(s[i]=='o' && idx[3]<i){
    //         idx.push_back(i);
    //         break;
    //     }
    // }

    // // for(int val : idx){
    // //     cout << val << " ";
    // // }

    // if(is_sorted(idx.begin(),idx.end())) cout << "YES";
    // else cout << "NO";

    return 0;
}