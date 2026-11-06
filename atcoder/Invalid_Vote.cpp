#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool func(string s1, string s2){

    if(s1.size()!=s2.size()) return false;

    int cnt =0;

    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s2[i]) cnt++;
    }

    return cnt==1;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;

    vector<string> names(n); for(auto &x : names) cin>>x;
    // for(int i=0;i<n;i++){
    //     string x; cin>>x;
    //     names.insert(x);
    // }

    // for(auto val : names){
    //     cout << val << " ";
    // }

    vector<string> check(m); for(auto &x : check) cin>>x;
    // for(auto val : check){
    //     cout << val << " ";
    // }

    vector<int> cnt(n,0);

    for(int i=0;i<m;i++){

        string word = check[i];
        int exact=-1;

        for(int j=0;j<n;j++){
            if(names[j]==word){
                exact = j;
                break;
            }
        }

        if(exact!=-1){
            cnt[exact]++;
            continue;
        }


        int one_diff=0, diff_idx=-1;

        for(int i=0;i<n;i++){
            if(func(names[i],word)){
                one_diff++;
                diff_idx = i;
            }
        }

        if(one_diff == 1){
            cnt[diff_idx]++;
        }
    }

    // for(int i=0;i<n;i++){

    //     int sum =0;
    //     for(int j=0;j<m;j++){
    //         if(check[j]==names[i]) sum++;
    //     }

    //     cnt[i] = sum;
    //     sum =0;
    // }

    // for(int i=0;i<n;i++){
    //     bool found = false;
    //     for(int j=0;j<m;j++){
    //         int res = func(names[i],check[j]);
            
    //         if(res==1){
    //             cnt[i]++;
    //             found = true;
    //             break;
    //         }
    //     }

    //     if(found) break;

    
    // }

    

    for(auto val : cnt){
        cout << val << '\n';
    }



    return 0;
}

/*
    couldn't understand the second test case, how a = 2 and b=1

*/